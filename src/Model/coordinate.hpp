#ifndef __COORDINATE_HPP__
#define __COORDINATE_HPP__

#include <cmath>
#include <sstream>

struct coordinate {
    int row;
    int col;

    coordinate(int row = -1, int col = -1): row{row}, col{col} {}
    coordinate(const coordinate&) = default;

    coordinate operator+(const coordinate& other) const {
        return coordinate(row + other.row, col + other.col);
    }

    coordinate operator-(const coordinate& other) const {
        return coordinate(row - other.row, col - other.col);
    }

    int operator*(const coordinate& other) const {
        return row*other.row + col*other.col;
    }

    coordinate operator*(int scalar) const {
        return coordinate(row*scalar, col*scalar);
    }

    bool operator==(const coordinate& other) const {
        return row == other.row && col == other.col;
    }

    bool operator!=(const coordinate& other) const {
        return !(*this == other);
    }

    std::string stringify() {
        std::stringstream s;
        s << "(" << row << ", " << col << ")";
	return s.str();
    }
};

// rotates a vector by a given angle in degrees
coordinate rotate(const coordinate& v, double a) {
    a *= 3.14159265358979324/180.0;
    return coordinate(nearbyint(v.row*cos(a) - v.col*sin(a)), nearbyint(v.row*sin(a) + v.col*cos(a)));
}

// checks if two vectors exist on the same line
bool are_dependent(const coordinate& v, const coordinate& w) {
    return v * rotate(w, 90) == 0;
}
 
// checks if two vectors point in the same direction
bool are_equivalent(const coordinate& v, const coordinate& w) {
    return are_dependent(v, w) && v * w > 0;
}

#endif
