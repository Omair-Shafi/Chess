#ifndef __UPDATE_BOARD_HPP__
#define __UPDATE_BOARD_HPP__

#include "message.hpp"
#include "../Model/board.hpp"

class UpdateBoard: public Message {
    private:
        Board* board;

    public:
        UpdateBoard(Board* b): board{b} {}

        Board* get_board() {
            return board;
        }

        std::string getUIBoard() {
            std::stringstream ss;
            board->print(ss);

            return ss.str();
        }

        virtual std::string info() {
            return "Update board!";
        }

        virtual char m_type() {
            return 'b';
        }
};

#endif