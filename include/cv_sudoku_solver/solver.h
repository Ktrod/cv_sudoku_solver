#ifndef SOLVER_H_
#define SOLVER_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class Sudoku {
    private:
        vector<vector<int>> table;

        bool validLine(const vector<int> tbRow) const;
        bool validSubSquare(const vector<vector<int>> tbSubSquare) const;
    public:
        Sudoku (const vector<vector<int>> tb);

        vector<vector<int>> getTable() const { return table; };
        bool isValid() const;
        vector<vector<int>> solve() const;
        void printTable() const;

};



#endif