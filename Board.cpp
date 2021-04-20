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
     * @brief Printouts all the content on the board's map
     * 
     */
    void Board::show() {
        unsigned int index = 0;
        unsigned int column = 0;
        for (auto p : board_map) { 
            if (index == 0) {
                std::cout << p.second;
                index++;
                column = p.first.first; 
            }
            else {
                if (column != p.first.first) { 
                    std::cout << endl;
                    std::cout << p.second;
                    column = p.first.first;
                }
                else {
                    std::cout << p.second;
                }
            }    
        }
        cout << endl;
    }
};