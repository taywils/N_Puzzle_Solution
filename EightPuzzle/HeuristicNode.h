//
//  HeuristicNode.h
//  EightPuzzle
//
//  Created by Demetrious  Wilson on 12/23/14.
//  Copyright (c) 2014 Demetrious  Wilson. All rights reserved.
//

#ifndef __EightPuzzle__HeuristicNode__
#define __EightPuzzle__HeuristicNode__

#include "EightPuzzle.h"
#include "Board.h"

namespace EightPuzzle {
    
    class HeuristicNode {
    public:
        
        HeuristicNode(Board board);
        HeuristicNode(Board board, HeuristicNode* parent);
        
        void calculateScore(Board target);
        unsigned int getScore();
        
        Board board;
        HeuristicNode* parent;
        std::vector<HeuristicNode*> children;
        
    private:
        
        unsigned int score;
    };
}

#endif /* defined(__EightPuzzle__HeuristicNode__) */
