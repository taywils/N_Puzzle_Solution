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
    
    this->score = tempScore * calculateComplexityFactor();
}

unsigned int EightPuzzle::HeuristicNode::getScore() {
    return this->score;
}

unsigned int EightPuzzle::HeuristicNode::calculateComplexityFactor() {
    // Penalize board positions with high numbers of possible moves
    auto legalMoves = legalMoveTable[board.getZeroPosition()];
    return (unsigned int)legalMoves.size();
}
