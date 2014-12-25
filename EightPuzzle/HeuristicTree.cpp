#include "HeuristicTree.h"
#include "RandomSelector.h"

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
        Board newBoard{getRoot()->board.contents};
        
        newBoard.slide(idx);
        
        // Avoid adding the previous board position
        if(getRoot()->parent != nullptr && newBoard.contents == getRoot()->parent->board.contents) {
            continue;
        }

        newHeuristicNode = new HeuristicNode{newBoard, getRoot()};
        newHeuristicNode->calculateScore(Board(EightPuzzle::target));
        
        decisionVector.push_back(newHeuristicNode->getScore());
        
        root->children.push_back(newHeuristicNode);
    }
}

void EightPuzzle::HeuristicTree::move() {
    generateMoves();
    setRoot(getRoot()->children.at(makeDecision()));
    decisionVector.clear();
}

bool EightPuzzle::HeuristicTree::isSolved() {
    return 0 == getRoot()->getScore();
}

unsigned int EightPuzzle::HeuristicTree::makeDecision() {
    random_selector<> randSelector{};
    std::vector<unsigned int>::iterator minScoreIterator = std::min_element(std::begin(decisionVector), std::end(decisionVector));
    
    auto minScoreIndex = std::distance(std::begin(decisionVector), minScoreIterator);
    auto minScoreVal = decisionVector.at((unsigned)minScoreIndex);
    
    std::vector<unsigned int> temp;
    unsigned int tempIdx{0};
    for(auto v : decisionVector) {
        if(minScoreVal == v) {
            temp.push_back(tempIdx);
        }
        ++tempIdx;
    }
    
    return randSelector(temp);
}