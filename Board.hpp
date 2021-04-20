#include <string>
#include <map>
#include "Direction.hpp"
using namespace std;

namespace ariel {
    class Board {
        private:
            typedef pair <unsigned int, unsigned int> position;
            map <position, char> board_map;
            unsigned int max_column = 0;   
            unsigned int max_row = 0;
        public:
            Board();
		    void post(unsigned int row, unsigned int column, Direction direction, string const &content);
            string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
            void show();
	};
}