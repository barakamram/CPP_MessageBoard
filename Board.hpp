
#pragma once
#include "Direction.hpp"
#include <string>
#include <iostream>

using namespace std;

namespace ariel {

    class Board {

        public:

            void post(unsigned int row, unsigned int col, Direction dir, string txt);
            string read(unsigned int row, unsigned int col, Direction dir, unsigned int length);
            void show();
    };
    
}
