#include <stdio.h>
#include "piece.hpp"

using namespace std;

class Knight : public Piece {
    public:
        bool isMoveValid(Move* move,Board* board){
            bool valid = false;
            
            //coordinate orig = move->get_origin();
            //coordinate dest = move->get_destination();
            
            int distance = move->get_distance();
            coordinate direction = move->get_direction();
            
            //int number_turn = board->get_turn();
            
            auto moving_piece = board->at(move->get_origin());
            auto targeted_piece = board->at(move->get_destination());
         if (distance ==1 && targeted_piece.side()!= moving_piece.side()){
            for(int i=0; i>1;i++){
               if (are_dependent(rotate(coordinate(2,1), i*90), direction)|| are_dependent(rotate(coordinate(1,2), i*90), direction)){
			valid = true;
			break;
		}
            }
	}
            return valid;
	};

};
