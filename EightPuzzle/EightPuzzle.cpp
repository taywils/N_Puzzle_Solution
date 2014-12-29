#include "EightPuzzle.h"

namespace EightPuzzle {
    std::vector< std::vector<unsigned int> > legalMoveTable{
        {1, 3},
        {0, 4, 2},
        {1, 5},
        {0, 4, 6},
        {1, 3, 5, 7},
        {2, 4, 8},
        {3, 7},
        {4, 6, 8},
        {5, 7}
    };
    
    std::vector< std::vector<unsigned int> > manhattanTable {
        {
            0, 1, 2,
            1, 2, 3,
            2, 3, 4
        },
        {
            1, 0, 1,
            2, 1, 2,
            3, 2, 3
        },
        {
            2, 1, 0,
            3, 2, 1,
            4, 3, 2
        },
        {
            1, 2, 3,
            0, 1, 2,
            1, 2, 3
        },
        {
            2, 1, 2,
            1, 0, 1,
            2, 1, 2,
        },
        {
            3, 2, 1,
            2, 1, 0,
            3, 2, 1
        },
        {
            2, 3, 4,
            1, 2, 3,
            0, 1, 2
        },
        {
            3, 2, 3,
            2, 1, 2,
            1, 0, 1
        },
        {
            4, 3, 2,
            3, 2, 1,
            2, 1, 0
        }
    };
    
    std::vector<unsigned int> target{ 4, 0, 1, 2, 3, 5, 6, 7, 8 };

    unsigned int getManhattanDistFrom(int boardPosition, int targetPosition) {
        return manhattanTable.at((unsigned)boardPosition).at((unsigned)targetPosition);
    }

    Utility::Utility(unsigned int N, std::vector< unsigned int > target) :
        N(N),
        puzzleSize(N * N),
        target(target)
    {
        generateLegalMoveTable();
    }

    void Utility::generateLegalMoveTable() {
        int i{0};
        legalMoveTable.reserve(puzzleSize);

        while(i < puzzleSize) {
            std::vector<unsigned int> lm;
            int up = i - N;
            int down = i + N;
            int left = i - 1;
            int right = i + 1;

            if(up >= 0) {
                lm.push_back(up);
            }
            if(down < puzzleSize) {
                lm.push_back(down);
            }
            if(i % N != 0) {
                lm.push_back(left);
            }
            if(right % N != 0) {
                lm.push_back(right);
            }

            legalMoveTable.push_back(lm);
            ++i;
        }
    }

    std::vector< std::vector<unsigned int> > Utility::getLegalMoveTable() {
        return legalMoveTable;
    }

    void Utility::generateManhattanTables() {

    }

    std::vector< unsigned int > Utility::getTarget() {
        return target;
    }

    unsigned int Utility::getPuzzleSize() {
        return (unsigned int)puzzleSize;
    }
}
