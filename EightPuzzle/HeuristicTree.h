#ifndef __EightPuzzle__HeuristicTree__
#define __EightPuzzle__HeuristicTree__

#include "EightPuzzle.h"
#include "HeuristicNode.h"

namespace EightPuzzle {
    
    class PriorityCompare {
    public:
        // Minium priority goes to the top of the Heap
        bool operator()(const HeuristicNode* lhs, const HeuristicNode* rhs) {
            return lhs->getPriority() > rhs->getPriority();
        }
    };
    
    class HeuristicTree {
    public:

        HeuristicTree(HeuristicNode*, Utility*);

        std::priority_queue<HeuristicNode*, std::vector<HeuristicNode*>, PriorityCompare > priorityQueue;

        void setRoot(HeuristicNode*);
        HeuristicNode* getRoot();
        void move();
        int isSolved();
        Utility* getUtility();
        bool isBoardImpossible();
        
    private:
        
        void generateMoves();
        bool doesBoardHaveSolution();
        unsigned int makeDecision();
        HeuristicNode* makeDecisionRefactor();

        Utility* utility;
        HeuristicNode* root;
        std::vector<unsigned int> decisionVector;
        bool impossibleToSolve;
    };
}

#endif
