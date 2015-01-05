#include "HeuristicNode.h"

EightPuzzle::HeuristicNode::HeuristicNode(EightPuzzle::Board board) :
board(board) {
    
}

EightPuzzle::HeuristicNode::HeuristicNode(EightPuzzle::Board board, HeuristicNode* parent) :
board(board),
parent(parent){
    moves = 0;
}

void EightPuzzle::HeuristicNode::calculateScore(Utility* utility) {
    unsigned int tempScore{ 0 };
    size_t targetSize = utility->getTarget().size();

    for(size_t i = 1; i < targetSize; ++i) {
        tempScore += utility->getManhattanDistFrom(board.contents.at(i), utility->getTarget().at(i));
    }

    this->score = tempScore;

    calculateMovement();
}

unsigned int EightPuzzle::HeuristicNode::getScore() const {
    return this->score;
}

void EightPuzzle::HeuristicNode::calculateMovement() {
    // The number of moves is equal to the distance from the root to the current node
    HeuristicNode* nodeWalker = this;
    while(nodeWalker->parent != nullptr) {
        ++moves;
        nodeWalker = nodeWalker->parent;
    }
}

unsigned int EightPuzzle::HeuristicNode::getMoves() const {
    return this->moves;
}

unsigned int EightPuzzle::HeuristicNode::getPriority() const {
    return getScore() + getMoves();
}