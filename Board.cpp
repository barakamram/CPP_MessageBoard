
#include "Board.hpp"
#include <iostream>
#include "Direction.hpp"
#include <string>
#include <stdexcept>
using namespace std;
namespace ariel {

    void Board::post(unsigned int row, unsigned int col, Direction dir, string txt){
        if (dir == Direction::Horizontal) {
          this->R = (unsigned int)max(row,(this->R));
          this->C = (unsigned int)max((int)(col + txt.length()),(int)(this->C));
          for (uint i = 0; i < txt.length(); i++){
            this->board[row][col+i] = txt[i];
          }
        }
        else { // dir == Direction::Vertical
          this->C = (unsigned int)max(col,(this->C));
          this->R = (unsigned int)max((int)(row + txt.length()),(int)(this->R));
          for (uint i = 0; i < txt.length(); i++){
            this->board[row+i][col] = txt[i];
          }
        }
    }
    string Board::read(unsigned int row, unsigned int col, Direction dir, unsigned int length){
        if (length == 0){
          return "";
        }
        string message;
        if(row > getR() || col > getC()) {
          for (uint i = 0; i < length; i++){
            message += '_';
          }
          return message;
        }
        if (dir == Direction::Horizontal) {
          for (int i = 0; i < length && col < getC(); i++) {
             if (board[row][col] == 0) {
               message += empty;
               col++;
             }
             else{
               message += this->board[row][col++];
             }
           }
         }
          else {  // dir == Direction::Vertical
           for (int i = 0; i < length && row < getR(); i++) {
             if (board[row][col] == 0) {
               message += empty;
               row++;
             }
             else{
               message += this->board[row++][col];
             }
           }
        }
        while (length > message.length()){
          message += empty;
        }
        return message;
    }
    void Board::show(){
        for (uint i = 0; i < getR(); i++){
            for (uint j = 0; j < getC(); j++){
                cout << this->board[i][j] << " ";
            }
            cout << "\n";
        }
    }

    Board::Board(){
      board.clear();
    }

}
