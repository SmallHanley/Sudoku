#include <iostream>
#include "sudoku.h"
using namespace std;

int main() {
    int g[][Sudoku::mapSide] = {{0, 3, 0, 4, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 8, 0, 0, 0},
        {6, 0, 0, 0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 9, 0, 0, 0},
        {0, 8, 0, 5, 3, 0, 0, 7, 2},
        {0, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 3, 9, 0, 0, 4, 0, 0},
        {0, 2, 4, 0, 0, 0, 0, 6, 0},
        {0, 0, 5, 0, 7, 0, 9, 0, 0}
    };
    Sudoku Generate;
    Generate.setSudoku(g);
    Generate.printMap();
    return 0;
}
