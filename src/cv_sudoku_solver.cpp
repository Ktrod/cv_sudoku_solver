#include <solver.h>
#include <iostream>

vector<vector<int>> testBoard{
    {5, 3, 0}, 
    {6, 0, 0},
    {0, 9, 8}
    };

int main() {

    Sudoku test_board(testBoard);    

    test_board.printTable();

    return 0;
}