#ifndef __MOVE_HPP__
#define __MOVE_HPP__

#include "message.hpp"
#include "../Model/coordinate.hpp"

class EndGame: public Message
{
    public:
        virtual std::string info()
        {
            return "Game Finished";
        }
	virtual char m_type()
	{
            return 'e';
        }
}
