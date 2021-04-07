
#pragma once
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <map>
#include <stdexcept>
using namespace std;
namespace ariel {

    class Board {

        public:
            unsigned int R = 0;
            unsigned int C = 0;
            map <unsigned int, map <unsigned int, char>> board;
            const char empty = '_';

        public:
            uint getR(){ return this->R; }
            uint getC(){ return this->C; }

        public:
            Board();
            void post(unsigned int row, unsigned int col, Direction dir, string txt);
            string read(unsigned int row, unsigned int col, Direction dir, unsigned int length);
            void show();

    };

}
