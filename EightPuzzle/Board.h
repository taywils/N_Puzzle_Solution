//
//  Board.h
//  EightPuzzle
//
//  Created by Demetrious  Wilson on 12/23/14.
//  Copyright (c) 2014 Demetrious  Wilson. All rights reserved.
//

#ifndef __EightPuzzle__Board__
#define __EightPuzzle__Board__


#include "EightPuzzle.h"

namespace EightPuzzle {
    class Board {
    public:
        
        Board(std::vector<unsigned int> boardContents);
        Board() {};
        
        Board slide(unsigned int position);
        void print();
        
        std::vector<unsigned int> contents;
    };
}

#endif /* defined(__EightPuzzle__Board__) */
