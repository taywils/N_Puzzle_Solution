#include "Board.h"

EightPuzzle::Board::Board(std::vector<unsigned int> boardContents) : contents(boardContents) {
}

void EightPuzzle::Board::slide(unsigned int position) {
    unsigned int indexOfPosition{0};
    size_t contentsSize{contents.size()};
    
    for(unsigned int i = 0; i < contentsSize; ++i) {
        if(position == contents.at(i)) {
            indexOfPosition = i;
        }
    }
    
    std::swap(contents.at(0), contents.at(indexOfPosition));
}

void EightPuzzle::Board::print() {
    std::map<unsigned int, unsigned int> printMap;
    size_t contentsSize = contents.size();
    size_t i = 0;
    
    for(; i < contentsSize; ++i) {
        printMap[contents.at(i)] = (unsigned int)i;
    }
    
    for(i = 0; i < contentsSize; ++i) {
        if(i > 0 && i % 3 == 0) {
            std::cout << std::endl;
        }
        
        std::cout << " " << printMap.at((unsigned int)i) << " ";
    }
    std::cout << std::endl;
}

unsigned int EightPuzzle::Board::getZeroPosition() {
    return contents.at(0);
}