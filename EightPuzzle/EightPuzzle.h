#ifndef __EightPuzzle__EightPuzzle__
#define __EightPuzzle__EightPuzzle__

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <random>
#include <iterator>

namespace EightPuzzle {
    // Values
    extern std::vector< std::vector<unsigned int> > legalMoveTable;
    extern std::vector< std::vector<unsigned int> > manhattanTable;
    extern std::vector< unsigned int > target;
    
    // Functions
    extern unsigned int getManhattanDistFrom(int, int);
}

#endif
