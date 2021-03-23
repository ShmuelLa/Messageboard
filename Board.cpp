#include <string>
#include "Board.hpp"
#include "Direction.hpp"
using namespace std;

namespace ariel {
    void Board::post(unsigned int row, unsigned int column, Direction direction, string const &content) {
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length) {
        string result = "sd";
        result += this->board[0][0];
        return result;
    }
    
    void Board::show() {
    }
};