/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

void generate_board(Board board, unsigned int dimensions, string message) {
    cout << endl;
    for (unsigned int i=0; i <= dimensions*2; i++) {
        for (unsigned int j=0; j <= dimensions*2; j++) {
            board.post(i, j, Direction::Vertical, " ");    
            board.post(i, j, Direction::Horizontal, " ");    
        }
    }
    board.post(dimensions, dimensions, Direction::Vertical, string(dimensions, '#'));
    board.post(dimensions, dimensions+1, Direction::Vertical, string(dimensions, '#'));
    board.post(0, 0, Direction::Vertical, string(dimensions*2, ' '));
    board.post(0, 5, Direction::Horizontal, message);
    board.post(1, 1, Direction::Vertical, string(dimensions, '|'));
    board.post(1, 1, Direction::Horizontal, string(dimensions*2, '-'));
    board.post(dimensions, 1, Direction::Horizontal, string(dimensions*2, '-'));
    board.post(2, dimensions*2, Direction::Vertical, string(dimensions-2, '|'));
    board.show();
    std::cin.ignore();
}

int main() {
    Board board;
    unsigned int dimensions = 3;
    generate_board(board, dimensions, "     This is a cute board");
    dimensions*=2;
    generate_board(board, dimensions, "     This is a board");
    dimensions*=2;
    generate_board(board, dimensions, "     This is a bigger board");
    dimensions*=2;
    generate_board(board, dimensions, "     This is a serious board");
}