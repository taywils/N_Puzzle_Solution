//
//  EightPuzzle.h
//  EightPuzzle
//
//  Created by Demetrious  Wilson on 12/23/14.
//  Copyright (c) 2014 Demetrious  Wilson. All rights reserved.
//

#ifndef __EightPuzzle__EightPuzzle__
#define __EightPuzzle__EightPuzzle__

#include <iostream>
#include <vector>
#include <algorithm>

namespace EightPuzzle {
    // Values
    extern std::vector< std::vector<unsigned int> > legalMoveTable;
    extern std::vector< std::vector<unsigned int> > manhattanTable;
    extern std::vector< unsigned int > target;
    
    // Functions
    extern unsigned int getManhattanDistFrom(int, int);
}

#endif /* defined(__EightPuzzle__EightPuzzle__) */
