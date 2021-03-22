
#include "Board.hpp"
#include "doctest.h"
#include "Direction.hpp"
using namespace ariel;
#include <string>
using namespace std;



TEST_CASE("Good code"){
    ariel::Board board;
    board.post(1, 1,Direction::Horizontal, "hello");
    CHECK(board.read(1, 1, Direction::Horizontal, 5) == "hello");
    board.post(1, 2, Direction::Horizontal, "Hola");
    CHECK(board.read(1, 2, Direction::Horizontal, 4) == "Hola");
    CHECK(board.read(50, 100, Direction::Horizontal, 2) == "__");
    CHECK(board.read(50, 100, Direction::Vertical, 2) == "__");
    board.post(10, 20, Direction::Vertical, "hola");
    CHECK(board.read(10, 20, Direction::Vertical, 4) == "hola");
    board.post(53, 42, Direction::Vertical, "wellow");
    CHECK(board.read(52, 43, Direction::Vertical, 6) == "wellow");
    board.post(10000, 10000, Direction::Vertical, "hola_chikitas");
    CHECK(board.read(10000, 10000, Direction::Vertical, 13) == "hola_chikitas");
    board.post(480000, 500000, Direction::Horizontal, "Barak");
    CHECK(board.read(5000, 3500, Direction::Vertical, 1) == "B");
    CHECK(board.read(5000, 3500, Direction::Vertical, 2) == "_a");
    CHECK(board.read(5000, 3500, Direction::Vertical, 1) == "r");
    CHECK(board.read(5000, 3500, Direction::Vertical, 2) == "a_");
    CHECK(board.read(5000, 3500, Direction::Vertical, 3) == "*k*");

}

TEST_CASE("Bad code"){
    ariel::Board board;
    board.post(5, 10, Direction::Vertical, " ");
    board.post(5, 10, Direction::Horizontal, " ");
    board.post(300000, 200000, Direction::Vertical, " ");
    CHECK(board.read(120, 600, Direction::Vertical, 7) == "fa iled");
    CHECK(board.read(1,10, Direction::Horizontal, 5) == "error");
}
