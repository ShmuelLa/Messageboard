/**
 * @file Main.cpp
 * @author Shmuel.Lavian
 * @brief Demo program for the Messageboard project
 * @version 1.1
 * @date 2021-04-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

/**
 * @brief Generates a board text art on the board map with a set dimension and message
 * 
 * @param board The board object to print the text art on
 * @param dimensions Value of dimensions in order to set the board size
 * @param message string of the message to print on top of the board
 */
void generate_board(Board board, unsigned int dimensions, string message) {
    cout << endl;
    for (unsigned int i=0; i <= dimensions*2+1; i++) {
        for (unsigned int j=0; j <= dimensions*2+2; j++) {
            board.post(i, j, Direction::Vertical, " ");    
            board.post(i, j, Direction::Horizontal, " ");    
        }
    }
    board.post(dimensions, dimensions, Direction::Vertical, string(dimensions+2, '#'));
    board.post(dimensions, dimensions+1, Direction::Vertical, string(dimensions+2, '#'));
    board.post(0, 0, Direction::Vertical, string(dimensions*2, ' '));
    board.post(0, 2, Direction::Horizontal, message);
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
    generate_board(board, dimensions, "This is a cute board");
    dimensions*=2;
    generate_board(board, dimensions, " This is a board");
    dimensions*=2;
    generate_board(board, dimensions, "  This is a bigger board");
    dimensions*=2;
    generate_board(board, dimensions, "And this is a serious board! (On another board..)");
}