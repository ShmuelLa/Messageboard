
/**
 * @file Test.cpp
 * @author Shmuel.Lavian
 * @brief tests for the second assignment messageboard
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <string>
#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Exceptions") {
    Board board;
    CHECK_THROWS(board.read(10000,10000,Direction::Horizontal,5));
    CHECK_THROWS(board.read(10000,10000,Direction::Vertical,5));
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"Shmuel"));
    CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"Shmuel"));
    CHECK_THROWS(board.read(300,300,Direction::Horizontal,6));
    CHECK_THROWS(board.read(300,300,Direction::Vertical,17));
    CHECK_NOTHROW(board.post(300,300,Direction::Horizontal,"Shmuel"));
    CHECK_NOTHROW(board.post(300,300,Direction::Vertical,"Shmuel"));
    CHECK_NOTHROW(board.read(300,300,Direction::Horizontal,6));
    CHECK_NOTHROW(board.read(300,300,Direction::Vertical,6));
}

TEST_CASE("Board changes") {
    Board board;
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"Shmuel"));
    CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"Shmuel"));
    CHECK(board.read(0,0,Direction::Horizontal,6) == "Shmuel");
    CHECK(board.read(0,0,Direction::Vertical,6) == "Shmuel");
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"T"));
    CHECK(board.read(0,0,Direction::Horizontal,6) == "Thmuel");
    CHECK(board.read(0,0,Direction::Vertical,6) == "Thmuel");
    CHECK_NOTHROW(board.post(0,1,Direction::Horizontal,"T"));
    CHECK(board.read(0,0,Direction::Horizontal,6) == "TTmuel");
    CHECK(board.read(0,0,Direction::Vertical,6) == "Thmuel");
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"KABAB"));
    CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"KABAB"));
    CHECK(board.read(0,0,Direction::Horizontal,5) == "KABAB");
    CHECK(board.read(0,0,Direction::Vertical,5) == "KABAB");
}


