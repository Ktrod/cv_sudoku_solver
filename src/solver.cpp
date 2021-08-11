#include <solver.h>
#include <iostream>

Sudoku::Sudoku (const vector<vector<int>> tb) : table(tb) {}

vector<vector<int>> Sudoku::solve() const {
    vector<vector<int>> solvedTable;


    return solvedTable;

}

bool Sudoku::isValid() const {
    
    bool is_valid;

    return is_valid;
}

void Sudoku::printTable() const {

    for (int i = 0; i < table[0].size() + ((table[0].size() / 3) + 1); i++) std::cout << ". "; //Print top row 

    std::cout << "" << std::endl;
    for (int i = 0; i < table.size(); i++){
        if (i % 3 == 0 && i != 0){ //Check if we've reach third horizontal box and print seperator line
            for (int k = 0; k < table[0].size() + ((table[0].size() / 3) + 1); k++) std::cout << ". "; 
            std::cout << "" << std::endl;
            std::cout << ".";
        }
        else {
            std::cout << ".";
        }
        for (int j = 0; j < table.size(); j++){
            std::cout << " ";
            std::cout << table[i][j];

            if (j + 1 == table.size()) { //Check if we've reach end of line and print seperator char plus a new line
                std::cout << " ." << std::endl;
            }
            else if ((j+1) % 3 == 0 && j != 0) { //Check if we've reached third vertical box and print seperator char 
                std::cout << " .";
            }
        }
    }

    for (int i = 0; i < table[0].size() + ((table[0].size() / 3) + 1); i++) std::cout << ". "; //Print bottom row

}