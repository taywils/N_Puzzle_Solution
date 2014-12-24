//
//  HeuristicTree.h
//  EightPuzzle
//
//  Created by Demetrious  Wilson on 12/23/14.
//  Copyright (c) 2014 Demetrious  Wilson. All rights reserved.
//

#ifndef __EightPuzzle__HeuristicTree__
#define __EightPuzzle__HeuristicTree__

#include "EightPuzzle.h"
#include "HeuristicNode.h"

namespace EightPuzzle {
    
    class HeuristicTree {
    public:
        
        HeuristicTree(HeuristicNode* root);
        
        void setRoot(HeuristicNode *node);
        HeuristicNode* getRoot();
        void move();
        bool isSolved();
        
    private:
        
        void generateMoves();
        HeuristicNode* root;
        std::vector<unsigned int> decisionVector;
    };
}

#endif /* defined(__EightPuzzle__HeuristicTree__) */
