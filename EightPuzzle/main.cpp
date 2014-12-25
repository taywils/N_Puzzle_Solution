#include "Board.h"
#include "HeuristicNode.h"
#include "HeuristicTree.h"

int main(int argc, const char * argv[]) {
    // For content Vectors
    // { index == number on board -> value == position on board }
    // Read out loud, zero is at location one, one is at location six and so on.
    std::vector<unsigned int> contents{ 1, 6, 3, 0, 7, 4, 8, 5, 2 };
    EightPuzzle::Board board(contents);
    EightPuzzle::HeuristicNode hn(board);
    EightPuzzle::HeuristicTree ht(&hn);

    ht.getRoot()->calculateScore(EightPuzzle::target);

    ht.getRoot()->board.print();

    std::cout << "Path of the blank space across the board" << std::endl;
    unsigned int moves = 0;
    while(!ht.isSolved()) {
        ht.move();
        ++moves;
    }
    std::cout << "\nTook " << moves << " moves to finish" << std::endl;

    ht.getRoot()->board.print();

    return 0;
}