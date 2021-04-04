
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
    CHECK(board.read(10000, 10000, Direction::Vertical, 5) == "hola_");
    board.post(5000, 3500, Direction::Vertical, "Barak");
    CHECK(board.read(5000, 3500, Direction::Horizontal, 1) == "B");
    CHECK(board.read(5000, 3500, Direction::Horizontal, 2) == "_a");
    CHECK(board.read(5000, 3502, Direction::Horizontal, 1) == "r");
    CHECK(board.read(5000, 3503, Direction::Horizontal, 2) == "a_");
    CHECK(board.read(5000, 3503, Direction::Horizontal, 3) == "_k_");

}

TEST_CASE("overriding"){
    ariel::Board board;
    board.post(0, 2, Direction::Vertical, "0000000000");
  	board.post(1, 2, Direction::Vertical, "0000000000");
  	board.post(2, 2, Direction::Vertical, "0000000000");
  	board.post(3, 2, Direction::Vertical, "0000000000");
  	board.post(4, 2, Direction::Vertical, "0000000000");
  	board.post(5, 2, Direction::Vertical, "0000000000");
  	board.post(6, 2, Direction::Vertical, "0000000000");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_0000000000");
  	board.post(0, 4, Direction::Horizontal, "1111111111");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_0010000000");
  	board.post(0, 5, Direction::Horizontal, "2222222222");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_0012000000");
  	board.post(0, 6, Direction::Horizontal, "3333333333");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_0012300000");
  	board.post(0, 7, Direction::Horizontal, "4444444444");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_0012340000");
  	board.post(0, 8, Direction::Horizontal, "5555555555");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_0012345000");
  	board.post(0, 9, Direction::Horizontal, "6666666666");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_0012345600");
  	board.post(0, 10, Direction::Horizontal, "7777777777");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_0012345670");
  	board.post(0, 11, Direction::Horizontal, "8888888888");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_0012345678");
  	board.post(0, 12, Direction::Horizontal, "9999999999");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_0012345678");
  	board.post(1, 1, Direction::Horizontal, "kkkkkkk");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_k0012345678");
  	board.post(2, 2, Direction::Horizontal, "ttttttt");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_kt012345678");
  	board.post(3, 3, Direction::Horizontal, "eeeeeeee");
  	CHECK(board.read(3, 1, Direction::Vertical, 12) == "_kte12345678");
  	board.post(5, 5, Direction::Horizontal, "fffffffff");
  	CHECK(board.read(6, 1, Direction::Vertical, 12) == "_kte1f345678");
  	board.post(6, 6, Direction::Horizontal, "sssssssss");
  	CHECK(board.read(6, 1, Direction::Vertical, 12) == "_kte1fs45678");  	
  }

}
