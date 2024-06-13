#ifndef __INVALID_MOVE_HPP__
#define __INVALID_MOVE_HPP__

#include "message.hpp"
#include "../Model/coordinate.hpp"
#include "move.hpp"

class InvalidMove: public Message {
    private:
		Move* m;
    public:
		InvalidMove(Move* move)
		{
			m = move;
		}

		Move* get_move()
		{
			return m;
		}

		virtual std::string info() {
				return "Invalid Move";
		}

		virtual char m_type()
		{
				return 'i';
        }
};

#endif
