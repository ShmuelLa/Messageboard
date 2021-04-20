#include <string>
#include <map>
#include "Direction.hpp"
using namespace std;

namespace ariel {
    class Board {
        private:
            typedef pair <unsigned int, unsigned int> position;
            map <position, char> board_map;     
        public:
            Board();
		    void post(unsigned int row, unsigned int column, Direction direction, string const &content);
            string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
            void show();
	};
}