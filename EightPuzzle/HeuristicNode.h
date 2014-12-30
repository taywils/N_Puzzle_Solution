#ifndef __EightPuzzle__HeuristicNode__
#define __EightPuzzle__HeuristicNode__

#include "EightPuzzle.h"
#include "Board.h"

namespace EightPuzzle {
    
    class HeuristicNode {
    public:
        
        HeuristicNode(Board);
        HeuristicNode(Board, HeuristicNode*);
        
        void calculateScore(Utility*);
        unsigned int getScore();
        
        Board board;
        HeuristicNode* parent;
        std::vector<HeuristicNode*> children;
        
    private:
        
        unsigned int score;
        unsigned int calculateComplexityFactor(Utility*);
    };
}

#endif
