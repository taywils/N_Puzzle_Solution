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
        unsigned int getScore() const;
        unsigned int getMoves() const;
        unsigned int getPriority() const;

        Board board;
        HeuristicNode* parent;
        std::vector<HeuristicNode*> children;
        
    private:

        void calculateMovement();

        unsigned int score;
        unsigned int moves;
    };
}

#endif
