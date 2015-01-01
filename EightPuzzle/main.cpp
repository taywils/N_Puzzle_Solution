#include "Board.h"
#include "HeuristicNode.h"
#include "HeuristicTree.h"

int main(int argc, const char * argv[]) {
    const unsigned int N{3};
    EightPuzzle::Board source({ 8, 7, 6, 1, 0, 5, 4, 3, 2 }, N);
    EightPuzzle::Board target({ 8, 0, 1, 2, 3, 4, 5, 6, 7 }, N);

    // For content Vectors
    // { index == number on board -> value == position on board }
    // Read out loud, zero is at location one, one is at location six and so on.
    std::vector<unsigned int> contents = source.contents;
    EightPuzzle::Board board(contents, N);

    EightPuzzle::HeuristicNode hn(board);

    EightPuzzle::Utility utility(N, target.contents);
    EightPuzzle::HeuristicTree ht(&hn, &utility);

    ht.getRoot()->calculateScore(ht.getUtility());

    ht.getRoot()->board.print();
    
    if(ht.isBoardImpossible()) {
        std::cout << "Impossible board" << std::endl;
    } else {
        int moves = 0;
        while(!ht.isSolved()) {
            ht.move();
            ++moves;
        }
        std::cout << "\nTook " << moves << " moves to finish" << std::endl;
        ht.getRoot()->board.print();
    }

    return 0;
}