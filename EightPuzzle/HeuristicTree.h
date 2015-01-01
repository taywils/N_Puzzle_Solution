#ifndef __EightPuzzle__HeuristicTree__
#define __EightPuzzle__HeuristicTree__

#include "EightPuzzle.h"
#include "HeuristicNode.h"

namespace EightPuzzle {
    
    class HeuristicTree {
    public:
        
        HeuristicTree(HeuristicNode*, Utility*);
        
        void setRoot(HeuristicNode*);
        HeuristicNode* getRoot();
        void move();
        int isSolved();
        unsigned int makeDecision();
        Utility* getUtility();
        bool isBoardImpossible();
        
    private:
        
        void generateMoves();
        bool doesBoardHaveSolution();

        Utility* utility;
        HeuristicNode* root;
        std::vector<unsigned int> decisionVector;
        bool impossibleToSolve;
    };
}

#endif
