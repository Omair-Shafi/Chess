#ifndef __KING_HPP__
#define __KING_HPP__

#include "piece.hpp"

class King : public Piece
{
public:
        King(): Piece() {}
	~King() {}
	virtual bool isMoveValid(Move*, Board*);
	int getValue() const { return value; }
	/*
 	* Implemented in move.hpp
 	* std::list<coordinate> getDirections(Board*);
 	*/
private:
	int value = 0; // king is not a capturable piece and has no value
};

#endif
