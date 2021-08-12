#include <solver.h>
#include <iostream>
#include <unordered_map>

Sudoku::Sudoku (vector<vector<int>> tb) : table(tb) {}


/*
PUBLIC FUNCTIONS
*/
vector<vector<int>> Sudoku::solve() const {
    vector<vector<int>> solvedTable = table;
    vector<vector<int>> indexes;


    for (int i = 0; i < solvedTable.size(); i++){
        for (int j = 0; j < solvedTable.size(); j++){
            if (solvedTable[i][j] == 0){
                indexes.push_back({i, j});
            }
        }
    }
        for (int i = 0; i < indexes.size(); i++){
           solvedTable[indexes[i][0]][indexes[i][1]]++;

            while(!isValid(solvedTable)){
                solvedTable[indexes[i][0]][indexes[i][1]]++;
                if (solvedTable[indexes[i][0]][indexes[i][1]]> 9){
                    solvedTable[indexes[i][0]][indexes[i][1]] = 0;

                    i = i - 2;
                }
            }
        }

    if (isSolved(solvedTable)) return solvedTable;
    else return table;
}


void Sudoku::printTable(vector<vector<int>> tb) const {

    for (int i = 0; i < tb[0].size() + ((tb[0].size() / 3) + 1); i++) std::cout << ". "; //Print top row 

    std::cout << "" << std::endl;
    for (int i = 0; i < tb.size(); i++){
        if (i % 3 == 0 && i != 0){ //Check if we've reach third horizontal box and print seperator line
            for (int k = 0; k < tb[0].size() + ((tb[0].size() / 3) + 1); k++) std::cout << ". "; 
            std::cout << "" << std::endl;
            std::cout << ".";
        }
        else {
            std::cout << ".";
        }
        for (int j = 0; j < tb.size(); j++){
            std::cout << " ";
            std::cout << tb[i][j];

            if (j + 1 == tb.size()) { //Check if we've reach end of line and print seperator char plus a new line
                std::cout << " ." << std::endl;
            }
            else if ((j+1) % 3 == 0 && j != 0) { //Check if we've reached third vertical box and print seperator char 
                std::cout << " .";
            }
        }
    }

    for (int i = 0; i < tb[0].size() + ((tb[0].size() / 3) + 1); i++) std::cout << ". "; //Print bottom row

}

/*
PRIVATE FUNCTIONS
*/

bool Sudoku::isValid(const vector<vector<int>> tb) const {
    bool valid_columns, valid_rows, valid_sub_squares;

    valid_columns = validColumns(tb);
    if (!valid_columns) return false;

    valid_rows = validRows(tb);
    if (!valid_rows) return false;

    valid_sub_squares = validSubSquares(tb);
    if (!valid_sub_squares) return false;

    return true;
}

bool Sudoku::validColumns(const vector<vector<int>> tb) const{
    std::unordered_map<int, int> vals;

    for (int i = 0; i < tb.size(); i++){
        for (int j = 0; j < tb.size(); j++){
            if (tb[j][i] < 0 || tb[j][i] > 9) return false;

            if (tb[j][i] != 0) vals[tb[j][i]]++;
        }

        for (auto nums : vals){
            if(nums.second > 1) return false;
        }
        vals.clear();
    }
    return true;
}

bool Sudoku::validRows(const vector<vector<int>> tb) const{
    std::unordered_map<int, int> vals;

    for (int i = 0; i < tb.size(); i++){
        for (int j = 0; j < tb.size(); j++){
            if (tb[i][j] < 0 || tb[i][j] > 9) return false;

            if (tb[i][j] != 0) vals[tb[i][j]]++;
        }

        for (auto nums : vals){
            if(nums.second > 1) return false;
        }
        vals.clear();
    }
    return true;
}

bool Sudoku::validSubSquares(const vector<vector<int>> tb) const{
    std::unordered_map<int, int> vals;

    for (int i = 2; i < tb.size(); i +=3){
        for (int j = 2; j < tb.size(); j += 3){
            vals[tb[i][j]]++;
            vals[tb[i][j - 1]]++;
            vals[tb[i][j - 2]]++;
            vals[tb[i - 1][j]]++;
            vals[tb[i - 2][j]]++;
            vals[tb[i - 1][j - 1]]++;
            vals[tb[i - 2][j - 1]]++;
            vals[tb[i - 1][j - 2]]++;
            vals[tb[i - 2][j - 2]]++;

            for (auto nums : vals){
                if(nums.first != 0 && nums.second > 1) return false;
            } 
            vals.clear();
        }
    }
    return true;
}

bool Sudoku::isSolved(const vector<vector<int>> tb) const {
    if(!isValid(tb)) return false;

    for (int i = 0; i < tb.size(); i++){
        for (int j = 0; j < tb.size(); j++){
            if (tb[i][j] == 0) return false;
        }
    }
    return true;
}