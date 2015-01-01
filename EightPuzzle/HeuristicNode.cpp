#include "HeuristicNode.h"

EightPuzzle::HeuristicNode::HeuristicNode(EightPuzzle::Board board) :
board(board) {
    
}

EightPuzzle::HeuristicNode::HeuristicNode(EightPuzzle::Board board, HeuristicNode* parent) :
board(board),
parent(parent) {
}

void EightPuzzle::HeuristicNode::calculateScore(Utility* utility) {
    unsigned int tempScore{ 0 };
    size_t targetSize = utility->getTarget().size();

    for(size_t i = 1; i < targetSize; ++i) {
        tempScore += utility->getManhattanDistFrom(board.contents.at(i), utility->getTarget().at(i));
    }

    this->score = tempScore;
}

unsigned int EightPuzzle::HeuristicNode::getScore() {
    return this->score;
}

unsigned int EightPuzzle::HeuristicNode::calculateComplexityFactor(Utility* utility) {
    // Penalize board positions with high numbers of possible moves
    auto legalMoves = utility->getLegalMoveTable()[board.getZeroPosition()];
    return (unsigned int)legalMoves.size();
}
