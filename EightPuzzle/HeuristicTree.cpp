//
//  HeuristicTree.cpp
//  EightPuzzle
//
//  Created by Demetrious  Wilson on 12/23/14.
//  Copyright (c) 2014 Demetrious  Wilson. All rights reserved.
//

#include "HeuristicTree.h"

EightPuzzle::HeuristicTree::HeuristicTree(HeuristicNode* root) : root(root) {
    
}

void EightPuzzle::HeuristicTree::setRoot(EightPuzzle::HeuristicNode *node) {
    this->root = node;
}

EightPuzzle::HeuristicNode* EightPuzzle::HeuristicTree::getRoot() {
    return this->root;
}

void EightPuzzle::HeuristicTree::generateMoves() {
    std::vector<unsigned int> legalMoveVector = legalMoveTable[root->board.contents[0]];
    
    for(auto idx : legalMoveVector) {
        HeuristicNode* newHeuristicNode;
        Board newBoard{root->board.contents};
        
        newBoard.slide(idx);
        
        newHeuristicNode = new HeuristicNode{newBoard, root};
        newHeuristicNode->calculateScore(Board(EightPuzzle::target));
        
        decisionVector.push_back(newHeuristicNode->getScore());
        
        root->children.push_back(newHeuristicNode);
    }
}

void EightPuzzle::HeuristicTree::move() {
    generateMoves();
    
    std::vector<unsigned int>::iterator minScoreIterator =
    std::min_element(std::begin(decisionVector), std::end(decisionVector));
    
    auto minScoreIndex = std::distance(std::begin(decisionVector), minScoreIterator);
    
    setRoot(root->children.at((unsigned)minScoreIndex));
}

bool EightPuzzle::HeuristicTree::isSolved() {
    return 0 == getRoot()->getScore();
}