#ifndef SOLVER_H_
#define SOLVER_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class Sudoku {
    private:
        vector<vector<int>> table;

        bool validColumns(const vector<vector<int>> tb) const;
        bool validRows(const vector<vector<int>> tb) const;
        bool validSubSquares(const vector<vector<int>> tb) const;
        bool isValid(const vector<vector<int>> tb) const;

        bool isSolved(const vector<vector<int>> tb) const;
    public:
        Sudoku (vector<vector<int>> tb);

        vector<vector<int>> getTable() const { return table; };
        
        vector<vector<int>> solve() const;
        void printTable(vector<vector<int>> tb) const;

};



#endif