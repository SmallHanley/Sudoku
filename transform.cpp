#include <iostream>
#include "sudoku.h"
using namespace std;

int main() {
    int i, j, m, x, y, input[Sudoku::mapSide][Sudoku::mapSide];
    for(i = 0; i < Sudoku::mapSide; i++) {
        for(j = 0; j < Sudoku::mapSide; j++) {
            cin >> input[i][j];
        }
    }
    Sudoku Transform;
    Transform.setSudoku(input);
    while(1) {
        cin >> m;
        if(m == 0)  break;
        switch(m) {
        case 1:
            cin >> x >> y;
            Transform.swapNum(x, y);
            break;
        case 2:
            cin >> x >> y;
            Transform.swapRow(x, y);
            break;
        case 3:
            cin >> x >> y;
            Transform.swapCol(x, y);
            break;
        case 4:
            cin >> x;
            Transform.rotate(x);
            break;
        case 5:
            cin >> x;
            Transform.flip(x);
            break;
        }
    }
    Transform.printMap();
    return 0;
}
