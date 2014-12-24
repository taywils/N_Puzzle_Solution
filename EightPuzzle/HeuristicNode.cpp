//
//  HeuristicNode.cpp
//  EightPuzzle
//
//  Created by Demetrious  Wilson on 12/23/14.
//  Copyright (c) 2014 Demetrious  Wilson. All rights reserved.
//

#include "HeuristicNode.h"

EightPuzzle::HeuristicNode::HeuristicNode(EightPuzzle::Board board) :
board(board) {
    
}

EightPuzzle::HeuristicNode::HeuristicNode(EightPuzzle::Board board, HeuristicNode* parent) :
board(board),
parent(parent) {
}

void EightPuzzle::HeuristicNode::calculateScore(Board target) {
    unsigned int tempScore{ 0 };
    size_t targetSize = target.contents.size();
    
    for(size_t i = 0; i < targetSize; ++i) {
        tempScore += getManhattanDistFrom(board.contents.at(i), target.contents.at(i));
    }
    
    this->score = tempScore;
}

unsigned int EightPuzzle::HeuristicNode::getScore() {
    return this->score;
}
