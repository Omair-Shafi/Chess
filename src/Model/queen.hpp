#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "piece.hpp"

class Queen : public Piece
{
public:
	virtual bool isMoveValid(Move*, Board*);
	int getValue() const { return value; }
	/*
 	* Implemented in move.hpp
 	* std::list<coordinate> getDirections(Board*);
 	*/
private:
	int value = 9;
};

#endif
