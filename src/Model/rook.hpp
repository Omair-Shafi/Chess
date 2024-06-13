#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include "piece.hpp"

class Rook : public Piece
{
public:
	virtual bool isMoveValid(Move*, Board*);
	int getValue() const { return value; }
	/*
 	* Implemented in move.hpp
 	* std::list<coordinate> getDirections(Board*);
 	*/
private:
	int value = 5;
};

#endif
