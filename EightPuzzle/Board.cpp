//
//  Board.cpp
//  EightPuzzle
//
//  Created by Demetrious  Wilson on 12/23/14.
//  Copyright (c) 2014 Demetrious  Wilson. All rights reserved.
//

#include "Board.h"

EightPuzzle::Board::Board(std::vector<unsigned int> boardContents) : contents(boardContents) {
}

EightPuzzle::Board EightPuzzle::Board::slide(unsigned int position) {
    Board newBoard;
    
    unsigned int temp = contents[position];
    contents[0] = temp;
    
    newBoard.contents = contents;
    
    return newBoard;
}

void EightPuzzle::Board::print() {
    size_t contentsSize = contents.size();
    
    for(size_t i = 0; i < contentsSize; ++i) {
        if(i > 0 && i % 3 == 0) {
            std::cout << std::endl;
        }
        
        std::cout << " " << contents[i] << " ";
    }
    std::cout << std::endl;
}