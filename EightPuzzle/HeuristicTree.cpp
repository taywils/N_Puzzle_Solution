#include "HeuristicTree.h"
#include "RandomSelector.h"
#include <cassert>

EightPuzzle::HeuristicTree::HeuristicTree(HeuristicNode* root, Utility* utility) :
    root(root),
    utility(utility)
{
    impossibleToSolve = !doesBoardHaveSolution();
}

void EightPuzzle::HeuristicTree::setRoot(EightPuzzle::HeuristicNode *node) {
    this->root = node;
}

EightPuzzle::HeuristicNode* EightPuzzle::HeuristicTree::getRoot() {
    return this->root;
}

void EightPuzzle::HeuristicTree::generateMoves() {
    std::vector<unsigned int> legalMoveVector = getUtility()->getLegalMoveTable()[root->board.getZeroPosition()];

    for(auto idx : legalMoveVector) {
        HeuristicNode* newHeuristicNode;
        Board newBoard{getRoot()->board.contents, utility->getN()};

        newBoard.slide(idx);

        // Avoid adding the previous board position
        if(getRoot()->parent != nullptr
           && newBoard.contents == getRoot()->parent->board.contents) {
            continue;
        }

        newHeuristicNode = new HeuristicNode{newBoard, getRoot()};
        newHeuristicNode->calculateScore(getUtility());

        decisionVector.push_back(newHeuristicNode->getScore());
        
        root->children.push_back(newHeuristicNode);
    }
}

void EightPuzzle::HeuristicTree::move() {
    generateMoves();

    unsigned int decisionIndex = makeDecision();
    EightPuzzle::HeuristicNode* destinationNode = getRoot()->children.at(decisionIndex);
    setRoot(destinationNode);

    std::cout << std::endl;
    getRoot()->board.print();

    decisionVector.clear();
}

int EightPuzzle::HeuristicTree::isSolved() {
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

EightPuzzle::Utility* EightPuzzle::HeuristicTree::getUtility() {
    return utility;
}

// Based on notes from https://www.cs.princeton.edu/courses/archive/fall12/cos226/assignments/8puzzle.html
bool EightPuzzle::HeuristicTree::doesBoardHaveSolution() {
    bool isThereAPossibleSolution{false};
    auto boardContents = getRoot()->board.contents;

    unsigned int blankIndex{0};
    for(unsigned int i = 0; i < boardContents.size(); ++i) {
        if(boardContents.at(i) == 0) {
            blankIndex = i;
        }
    }

    unsigned int blankRowNumber = blankIndex / getUtility()->getN();

    size_t i{1};
    int j = (int)i - 1;
    unsigned int inversions{0};

    // The inversion calculation ignores the zero value
    auto zeroIterator = find(boardContents.begin(), boardContents.end(), 0);
    if(zeroIterator != boardContents.end()) {
        boardContents.erase(zeroIterator);
    }

    while(i < boardContents.size()) {
        if(boardContents.at(j) > boardContents.at(i)) {
            inversions++;
        }
        
        --j;
        
        if(j < 0) {
            ++i;
            j = (int)i - 1;
        }
    }

    if(getUtility()->getPuzzleSize() % 2 == 0) { // Even numbered board size
        isThereAPossibleSolution = ((inversions + blankRowNumber) % 2 != 0 );
    } else { // Odd numbered board size
        isThereAPossibleSolution = (inversions % 2 == 0);
    }

    return isThereAPossibleSolution;
}

bool EightPuzzle::HeuristicTree::isBoardImpossible() {
    return impossibleToSolve;
}