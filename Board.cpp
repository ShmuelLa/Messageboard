/**
 * @file Board.cpp
 * @author Shmuel.Lavian
 * @brief 
 * @version 1
 * @date 2021-04-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <string>
#include <iostream>
#include "Board.hpp"
#include "Direction.hpp"
using namespace std;

namespace ariel {

    /**
     * @brief Construct a new Board:: Board object
     * 
     */
    Board::Board(){};
    
    /**
     * @brief posts a string on the board by dividing it into chars and adding to the main map
     * 
     * @param row unsigned int representing the row number to start from
     * @param column unsigned int representing the column number to start from
     * @param direction object representing the direction to post Vertical/Horizontal
     * @param content string of the content to post on the board
     */
    void Board::post(unsigned int row, unsigned int column, Direction direction, string const &content) {
        for (size_t i = 0; i < content.length(); i++) {
            board_map[make_pair(row, column)] = content.at(i); 
            if (Direction::Horizontal == direction) {
                column++;
            }
            else {
                row++;
            }
        }
        if (column > max_column) {
            max_column = column;
        }
        if (row > max_row) {
            max_row = row;
        }
    }

    /**
     * @brief 
     * 
     * @param row unsigned int representing the row number to start from
     * @param column unsigned int representing the column number to start from
     * @param direction object representing the direction to post Vertical/Horizontal
     * @param length the number of chars to read from the board
     * @return string output of the content received from the board
     */
    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length) {
        string result;
        char current_char = '_';
        for (int i = 0; i < length; i++) {           
            if (board_map[make_pair(row,column)] > 0) {
                current_char = board_map[make_pair(row,column)];
            }
            else {
                current_char = '_'; 
            }
            result += current_char;
            if (Direction::Horizontal==direction) {
                column++;
            }
            else {
                row++;
            }
        }       
        return result;
    }
    
    /**
     * @brief Printouts all the content on the board's map using the read() function
     * 
     */
    void Board::show() {
        for (unsigned int i = 0; i < max_column; i++) {
            cout << read(i, 0, Direction::Horizontal, max_column) << endl;;
        }
    }
};