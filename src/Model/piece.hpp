#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include "../Messages/move.hpp"
#include "board.hpp"

class Piece {
    public:
	virtual ~Piece() {}
        virtual bool isMoveValid(Move*, Board*) = 0;
};

#endif
