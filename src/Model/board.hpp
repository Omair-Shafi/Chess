#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "coordinate.hpp"
#include "../Messages/move.hpp"

class Board {
private:
    char* board;
    int value;
    int depth;
    coordinate wk;
    coordinate bk;

public:
    class piece_info;
    class piece_iterator;
    class path_iterator;
    
    Board(): board{new char[65]}, value{0}, depth{0}, wk{coordinate(0,4)}, bk{coordinate(7,3)} {
        std::string order = "RNBQKBNRPPPPPPPP";
        for(int i = 0; i < 64; ++i)
            board[i] = (1 < i/8 && i/8 < 6? ' ': (i/16 == 0? order[i]: order[15 - i%16] + 32));
        board[64] = '\0';
    }

    Board(const Board& other): board{new char[65]}, value{other.value}, depth{other.depth} {
        for(int i = 0; i < 65; ++i)
            this->board[i] = other.board[i];
    }

    Board(Board&& other): board{other.board}, value{other.value}, depth{other.depth} { other.board = nullptr; }
    ~Board() { delete[] board; }
    
    // at: get piece at a specific position on the board
    char at(int x) const { return board[x]; }
    char at(int row, int col) const { return at(row*8 + col); }
    piece_info at(const coordinate& pos) const { return piece_info(new coordinate(pos), at(pos.row, pos.col), side(pos.row, pos.col)); }

    // move: return a new board with a move applied to it
    Board* move(const coordinate& origin, const coordinate& destination, int piece_value) {
        Board* b = new Board(*this);

        if(at(origin.row, origin.col) == 'K')
            b->bk = destination;
        else if(at(origin.row, origin.col) == 'k')
            b->wk = destination;

	    b->board[origin.row*8 + origin.col] = ' ';
        b->board[destination.row*8 + destination.col] = at(origin.row, origin.col);
        ++b->depth;
        b->value += piece_value*side(origin.row, origin.col);

        return b;
    }
    
    // side: get the side associated with a piece at a specified position
    int side(int x) const { return at(x) == ' '? 0: at(x) >= 'a'? 1: -1; }
    int side(int row, int col) const { return side(row*8 + col); }

    // get_value: returns evaluation of the current board state
    int get_value() const { return value + (value < 0? 1: -1)*depth; }

    // get_turn: returns current turn (0 refers to initial board)
    int get_turn() const { return depth; }

    coordinate get_king(int side) const { return side == 1? wk: bk; }

    void print(std::ostream& out) {
        for(int i = 0; i < 64; i++) {    
            out << board[i];
            if(i%8 == 7)
                out << std::endl;
        }
    }

    /*************************************************************************************************
     *                                       ITERATORS
     * -----------------------------------------------------------------------------------------------
     * piece_iterator
     *   - iterates through all of the active pieces on the board
     * 
     * path_iterator
     *   - iterates through a path specified by the user
     * 
     *************************************************************************************************/   
    piece_iterator piece_begin() { return piece_iterator(this); }
    piece_iterator piece_end() { return piece_iterator(this, 64); }

    path_iterator path_begin(Move& move) { return path_iterator(this, move.get_origin(), move.get_destination(), move.get_direction()); }
    path_iterator path_begin(const coordinate& origin, const coordinate& destination, const coordinate& direction) { return path_iterator(this, origin, destination, direction); }
    path_iterator path_end() { return path_iterator(); }

    /*************************************************************************************************
     *                                  CLASS IMPLEMENTATIONS
     *************************************************************************************************/
    class piece_info {
        private:
            coordinate* _pos;
            char _piece;
            int _side;

        public:
            piece_info(coordinate* pos, char piece, int side): _pos{pos}, _piece{piece}, _side{side} {}
            piece_info(piece_info&& other): _pos{other._pos}, _piece{other._piece}, _side{other._side} {other._pos == nullptr;}
            ~piece_info() {delete _pos;}

            coordinate pos() { return *_pos; }
            char piece() { return _piece; }
            int side() { return _side; }
            bool hasPiece() { return _side != 0; }
            bool isWhite() { return _side == 1; }
    };

    class piece_iterator {
        private:
            Board* board;
            int pos;

        public:
            piece_iterator(Board* b, int x = 0): board{b}, pos{x} {}

            piece_iterator& operator++() {
                if(board->at(pos) != '\0')
                    ++pos;
                while(board->at(pos) == ' ')
                    ++pos;

                return *this;
            }

            piece_iterator operator++(int) {
                piece_iterator temp = *this;
                ++(*this);
                return temp;
            }

            piece_info operator*() {
                if(pos >= 64)
                    throw "iterator out of bounds!";
                
                return piece_info(new coordinate(pos/8, pos%8), board->at(pos), board->side(pos));
            }
            
            bool operator==(const piece_iterator& other) { return this->pos == other.pos; }
            bool operator!=(const piece_iterator& other) { return !(*this == other); }
    };

    class path_iterator {
        private:
            Board* board;
            coordinate current;
            coordinate begin;
            coordinate end;
            coordinate dir;

        public:
            path_iterator(): board{nullptr}, current{coordinate()}, begin{current}, end{current}, dir{current} {}

            path_iterator(Board* b, const coordinate& orig, const coordinate& dest, const coordinate& dir): board{b}, current{coordinate(orig)}, begin{orig}, end{dest}, dir{dir} {
                coordinate v = dest - orig;
                if(!are_equivalent(v, dir) ||
                   end.row > 7 || end.row < 0 ||
                   end.col > 7 || end.col < 0) {
                    std::stringstream ss;
                    ss << "can not iterate from (" << orig.row << ", " << orig.col << ") to ("
                       << dest.row << ", " << dest.col << ") using the direction (" << dir.row
                       << ", " << dir.col << ")\n";
                    throw std::invalid_argument(ss.str());
                }
            }

            path_iterator& operator++() {
                if(current != coordinate())
                    current = (current == end)? coordinate(): current + dir;
                return *this;
            }

            path_iterator operator++(int) {
                path_iterator temp = *this;
                ++(*this);
                return temp;
            }

            piece_info operator*() {
                if(current.row < 0 || current.row > 7 || current.col < 0 || current.col > 7 || current == coordinate())
                    throw std::out_of_range("iterator out of bounds!");
                
                return board->at(current);
            }
            
            bool operator==(const path_iterator& other) { return this->current == other.current; }
            bool operator!=(const path_iterator& other) { return !(*this == other); }
    };
};

#endif
