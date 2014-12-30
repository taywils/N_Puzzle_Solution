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

    class Utility {
    public:
        explicit Utility(unsigned int, std::vector< unsigned int >);

        std::vector< std::vector<unsigned int> > getLegalMoveTable();
        std::vector< unsigned int > getTarget();
        unsigned int getPuzzleSize();

    private:
        std::vector< std::vector<unsigned int> > legalMoveTable;
        std::vector< std::vector<unsigned int> > manhattanTables;
        std::vector< unsigned int > target;
        size_t puzzleSize;
        unsigned int N;

        void generateLegalMoveTable();
        void generateManhattanTables();
        std::vector<unsigned int> generateManhattanTable(int, int);
    };
}

#endif
