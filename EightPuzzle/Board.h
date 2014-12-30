#ifndef __EightPuzzle__Board__
#define __EightPuzzle__Board__

#include "EightPuzzle.h"

namespace EightPuzzle {
    class Board {
    public:
        
        Board(std::vector<unsigned int>, unsigned int);
        Board() {};
        
        void slide(unsigned int position);
        void print();
        unsigned int getZeroPosition();
        
        std::vector<unsigned int> contents;

    private:
        unsigned int N;
    };
}

#endif
