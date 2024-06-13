#ifndef __MOVE_HPP__
#define __MOVE_HPP__

#include "message.hpp"
#include "../Model/coordinate.hpp"

class Move: public Message {
    private:
        coordinate origin;
        coordinate destination;
        coordinate direction;
        int distance;
        int side;

    public:
        Move(const coordinate& origin, const coordinate& destination): Message(), origin{origin}, destination{destination} {
            direction = coordinate(destination - origin);
            int abs_row = direction.row * (direction.row < 0? -1: 1);
            int abs_col = direction.col * (direction.col < 0? -1: 1); 
            distance = abs_row;

            if(abs_col != 0 && (abs_col < abs_row || abs_row == 0)) {
                abs_row = abs_col;
                this->distance = abs_row;
            }
            else if(abs_row == 0)
                abs_row = 1;

            direction.row /= abs_row;
            direction.col /= abs_row;
        }

        void set_origin(const coordinate& c) {
            origin = c;
        }

        void set_destination(const coordinate& c) {
            destination = c;
        }

        coordinate get_direction() {
            return direction;
        }

        coordinate get_origin() {
            return origin;
        }

        coordinate get_destination() {
            return destination;
        }

        int get_distance() {
            return distance;
        }

        virtual std::string info() {
            std::stringstream ss;
            ss << "Move from (" << origin.row << ", " << origin.col
               << ") to (" << destination.row << ", " << destination.col << ")." << std::endl;
            return ss.str();
        }

        virtual char m_type() {
            return 'm';
        }
};

#endif
