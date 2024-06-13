#ifndef __LISTENER_HPP__
#define __LISTENER_HPP__

#include "observer.hpp"
#include <vector>

class Listener {
    protected:
        std::vector<Observer*>* observers;

    public:        
        Listener(): observers{new std::vector<Observer*>()} {}

        virtual ~Listener() { delete observers; }

        virtual void notifyObservers(Message* msg, Observer* src) {
            for(auto obs: *observers)
                if(obs != src)
                    obs->update(msg, src);
        }

        void addObserver(Observer* obs) { observers->push_back(obs); }

        bool removeObserver(Observer* obs) {
            bool found = false;
            for(auto i = observers->begin(); i != observers->end(); i++)
                if(*i == obs) {
                    observers->erase(i);
                    found = true;
                    break;
                }
            return found;
        }
};

#endif // __LISTENER_HPP__
