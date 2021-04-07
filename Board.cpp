/**
 * @file Board.cpp
 * @author Shmula.Lavian
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

    Board::Board(){};

    void Board::post(unsigned int row, unsigned int column, Direction direction, string const &content) {
        for (size_t i = 0; i < content.length(); i++) {
            brd[make_pair(row,column)] = content.at(i); 
            if (Direction::Horizontal == direction) column++;
            else row++;    
        }
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length) {
        string result;
        char default_char = '_';
        for (size_t i = 0; i < length; i++) {           
            if (brd[make_pair(row,column)] > 0) default_char = brd[make_pair(row,column)];
            else default_char = '_'; 
            result += default_char;
            if (Direction::Horizontal==direction) column++;
            else row++;
        }       
        return result;
    }
    
    void Board::show() {
        unsigned int index = 0;
        unsigned int column = 0;
        for(auto p : brd) { 
            if(index == 0) {
                std::cout << p.second << endl;
                index++;
                column = p.first.first; 
            }
            else {
                if (column != p.first.first) { 
                    std::cout << endl;
                    std::cout << p.second;
                    column = p.first.first;
                }
                else std::cout << p.second;         
            }    
        }
        cout << endl;
    }
};