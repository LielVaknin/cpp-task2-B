#pragma once

#include "Direction.hpp"
#include <string>
#include <map>
#include <climits>

const int extraTenChars = 10; // For show() method
const int extraFiveChars = 5; // For show() method

namespace ariel {
    class Board {
        std::map<unsigned int, std::map<unsigned int, char>> messageBoard;
        unsigned int minRow, minCol, maxRow, maxCol;
    public:
        Board() : minRow(UINT_MAX), minCol(UINT_MAX), maxRow(0), maxCol(0), messageBoard() {};

        void post(unsigned int row, unsigned int col, Direction direction, const std::string &message);

        std::string read(unsigned int row, unsigned int col, Direction direction, unsigned int length);

        void show();
    };
}

