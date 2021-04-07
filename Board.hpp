
#pragma once
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <map>
#include <stdexcept>
using namespace std;
namespace ariel {

    class Board {
        map <unsigned int, map <unsigned int, char>> board;
        unsigned int R = 0;
        unsigned int C = 0;
        const char empty = '_';

        public:
            void post(unsigned int row, unsigned int col, Direction dir, string txt);
            string read(unsigned int row, unsigned int col, Direction dir, unsigned int length);
            void show();
            ~Board();

    };

}
