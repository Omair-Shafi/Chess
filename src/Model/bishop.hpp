#include <stdio.h>
#include "piece.hpp"

using namespace std;

class Bishop : public Piece {
    public:
        bool isMoveValid(Move* move,Board* board){
            bool validMove = false;
            
            coordinate orig = move->get_origin();
            coordinate dest = move->get_destination();
            
            int distance = move->get_distance();
            coordinate direction = move->get_direction();
            
            int number_turn = board->get_turn();
            
            auto moving_piece = board->at(move->get_origin());
            auto targeted_piece = board->at(move->get_destination());

	//if(move->get_distance()>1){
	
	    if((are_dependent(coordinate(1,1) , direction)||are_dependent(coordinate(-1,1), direction)) && targeted_piece.side() != moving_piece.side()){
                auto it = board->path_begin(*move);
                it++;
                bool has = true;
                for(it; it != board->path_end(); it++){
                    if((*it).hasPiece() && (*it).pos()!=dest){
                        has = false;
                        break;
                    }
                }
                return has;
            }
            return validMove;
       
        };
};
