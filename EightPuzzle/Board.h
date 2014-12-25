#ifndef __EightPuzzle__Board__
#define __EightPuzzle__Board__

#include "EightPuzzle.h"

namespace EightPuzzle {
    class Board {
    public:
        
        Board(std::vector<unsigned int> boardContents);
        Board() {};
        
        void slide(unsigned int position);
        void print();
        
        std::vector<unsigned int> contents;
    };
}

#endif
