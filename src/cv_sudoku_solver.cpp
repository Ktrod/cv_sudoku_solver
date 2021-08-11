#include <solver.h>
#include <iostream>

vector<vector<int>> testBoard{
    {0, 0, 0, 0, 0, 0, 0, 7, 5},
    {0, 0, 0, 0, 8, 0, 0, 9, 4},
    {0, 0, 0, 5, 0, 0, 6, 0, 0},
    {0, 1, 0, 0, 0, 0, 2, 0, 0},
    {0, 0, 0, 9, 0, 0, 0, 5, 7},
    {0, 0, 6, 0, 0, 3, 0, 4, 0},
    {0, 0, 1, 0, 0, 0, 0, 2, 3},
    {0, 8, 0, 0, 0, 0, 0, 0, 6},
    {0, 6, 3, 2, 4, 0, 0, 0, 0}
};

int main() {

    Sudoku test_board(testBoard);    

    test_board.printTable();
    
    std::cout << " " << std::endl;

    std::cout << test_board.isValid() << std::endl;

    return 0;
}