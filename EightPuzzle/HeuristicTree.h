#ifndef __EightPuzzle__HeuristicTree__
#define __EightPuzzle__HeuristicTree__

#include "EightPuzzle.h"
#include "HeuristicNode.h"

namespace EightPuzzle {
    
    class HeuristicTree {
    public:
        
        HeuristicTree(HeuristicNode*);
        
        void setRoot(HeuristicNode*);
        HeuristicNode* getRoot();
        void move();
        bool isSolved();
        unsigned int makeDecision();
        
    private:
        
        void generateMoves();
        HeuristicNode* root;
        std::vector<unsigned int> decisionVector;
    };
}

#endif
