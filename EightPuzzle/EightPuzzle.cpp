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
    
    std::vector<unsigned int> target{
        1, 2, 3,
        4, 0, 5,
        6, 7, 8
    };
    
    unsigned int getManhattanDistFrom(int boardPosition, int targetPosition) {
        return manhattanTable.at((unsigned)boardPosition).at((unsigned)targetPosition);
    }
}
