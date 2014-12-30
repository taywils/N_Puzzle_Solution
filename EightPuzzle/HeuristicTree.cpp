#include "HeuristicTree.h"
#include "RandomSelector.h"
#include <cassert>

EightPuzzle::HeuristicTree::HeuristicTree(HeuristicNode* root, Utility utility) : root(root), utility(utility) {
    
}

void EightPuzzle::HeuristicTree::setRoot(EightPuzzle::HeuristicNode *node) {
    this->root = node;
}

EightPuzzle::HeuristicNode* EightPuzzle::HeuristicTree::getRoot() {
    return this->root;
}

void EightPuzzle::HeuristicTree::generateMoves() {
    std::vector<unsigned int> legalMoveVector = legalMoveTable[root->board.getZeroPosition()];

    for(auto idx : legalMoveVector) {
        HeuristicNode* newHeuristicNode;
        Board newBoard{getRoot()->board.contents};

        newBoard.slide(idx);

        // Avoid adding the previous board position
        if(getRoot()->parent != nullptr && newBoard.contents == getRoot()->parent->board.contents) {
            continue;
        }

        newHeuristicNode = new HeuristicNode{newBoard, getRoot()};
        newHeuristicNode->calculateScore(getUtility().getTarget());

        decisionVector.push_back(newHeuristicNode->getScore());
        
        root->children.push_back(newHeuristicNode);
    }
}

void EightPuzzle::HeuristicTree::move() {
    generateMoves();

    unsigned int decisionIndex = makeDecision();
    EightPuzzle::HeuristicNode* destinationNode = getRoot()->children.at(decisionIndex);
    setRoot(destinationNode);

    std::cout << destinationNode->board.getZeroPosition() << " ";

    decisionVector.clear();
}

bool EightPuzzle::HeuristicTree::isSolved() {
    return 0 == getRoot()->getScore();
}

unsigned int EightPuzzle::HeuristicTree::makeDecision() {
    random_selector<> randSelector{};
    std::vector<unsigned int>::iterator minScoreIterator = std::min_element(std::begin(decisionVector), std::end(decisionVector));

    auto minScoreVal = *minScoreIterator;

    std::vector<unsigned int> childrenIndexVector;
    unsigned int childrenIndex{0};

    for(auto v : decisionVector) {
        if(minScoreVal == v) {
            childrenIndexVector.push_back(childrenIndex);
        }
        ++childrenIndex;
    }

    return randSelector(childrenIndexVector);
}

EightPuzzle::Utility EightPuzzle::HeuristicTree::getUtility() {
    return utility;
}