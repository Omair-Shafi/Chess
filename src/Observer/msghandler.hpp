/* #ifndef __MSGHANDLER_HPP__
#define __MSGHANDLER_HPP__

#include "../Messages/move.hpp"
#include "listener.hpp"
#include "../Messages/update_board.hpp"
#include "../Messages/undo_move.hpp"
#include "../Messages/promotion.hpp"
#include "../Messages/invalid_move.hpp"

class MsgHandler {
    public:
        virtual void handle(Move*, Observer*) = 0;
        virtual void handle(UndoMove*, Observer*) = 0;
        virtual void handle(UpdateBoard*, Observer*) = 0;
        virtual void handle(Promotion*, Observer*) = 0;
        virtual void handle(InvalidMove*, Observer*) = 0;
        virtual void handle(EndGame*, Observer*) = 0;
};

#endif */