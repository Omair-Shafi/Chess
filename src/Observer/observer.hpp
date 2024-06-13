#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include "../Messages/message.hpp"

class Observer {
    public:
        virtual ~Observer() {}
	    virtual void update(Message* message, Observer* src) = 0;
};

#endif // __OBSERVER_HPP__
