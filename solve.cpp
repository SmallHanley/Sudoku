#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "sudoku.h"
using namespace std;

int main() {
    int input[Sudoku::mapSide][Sudoku::mapSide], i, j, ansNum;
    for(i = 0; i < Sudoku::mapSide; i++) {
        for(j = 0; j < Sudoku::mapSide; j++) {
            cin >> input[i][j];
        }
    }
    Sudoku Solve;
    Solve.setSudoku(input);
    Solve.solve(0);
    ansNum = Solve.getAnsNum();
    if(ansNum == 0)
        printf("0\n");
    if(ansNum == 1) {
        printf("1\n");
        Solve.printAns();
    }
    if(ansNum >= 2)
        printf("2\n");
    return 0;
}
