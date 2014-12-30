#ifndef __EightPuzzle__EightPuzzle__
#define __EightPuzzle__EightPuzzle__

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <random>
#include <iterator>

namespace EightPuzzle {
    class Utility {
    public:
        explicit Utility(unsigned int, std::vector< unsigned int >);

        std::vector< std::vector<unsigned int> > getLegalMoveTable();
        std::vector< std::vector<unsigned int> > getManhattanTable();
        std::vector< unsigned int > getTarget();
        unsigned int getPuzzleSize();
        unsigned int getManhattanDistFrom(int, int);
        unsigned int getN();

    private:
        std::vector< std::vector<unsigned int> > legalMoveTable;
        std::vector< std::vector<unsigned int> > manhattanTables;
        std::vector<unsigned int> target;
        size_t puzzleSize;
        unsigned int N;

        void generateLegalMoveTable();
        void generateManhattanTables();
        std::vector<unsigned int> generateManhattanTable(int, int);
    };
}

#endif
