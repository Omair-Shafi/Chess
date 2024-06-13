#include "king.hpp"

using namespace std;

bool King::isMoveValid(Move* move, Board* board)
{
	bool validMove = true;

	coordinate dir = move->get_direction();
	
	// if move distance is NOT 1 or move direction is not valid
	if (!(move->get_distance() == 1) ||  !(are_dependent(coordinate(1, 0), dir) || are_dependent(coordinate(0, 1), dir) ||
		are_dependent(coordinate(1, 1), dir) || are_dependent(coordinate(-1, 1), dir)))
	{
		return false;
	}

	coordinate orig = move->get_origin();
	coordinate dest = move->get_destination();

	// if distance is 1 and path is clear, check if there is a piece on landing coordinate
	if (board->at(dest).piece() != ' ') {
		// if there is a piece on landing coordinate, check if it's capturable
		if (board->at(orig).side() == board->at(dest).side()) {
			return false;
		}
	}
	return validMove;
}
