#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include "sudoku.h"
using namespace std;

Sudoku::Sudoku() {
    ansNum = 0;
    blankSize = 0;
}

int Sudoku::blockNum(int r, int c) {
    r /= blockSide;
    c /= blockSide;
    return r * blockSide + c;
}

void Sudoku::setSudoku(int input[][mapSide]) {
    int i, j;
    for(i = 0; i < mapSide; i++) {
        for(j = 0; j < mapSide; j++) {
            map[i][j] = input[i][j];
            if(map[i][j] == 0) {
                blank[blankSize][0] = i;
                blank[blankSize][1] = j;
                blankSize++;
            } else {
                row[i][map[i][j]]++;
                col[j][map[i][j]]++;
                block[blockNum(i, j)][map[i][j]]++;
            }
        }
    }
}

void Sudoku::printMap() {
    int i, j;
    for(i = 0; i < mapSide; i++) {
        for(j = 0; j < mapSide; j++) {
            if(j != (mapSide - 1))
                printf("%d ", map[i][j]);
            else
                printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

//transform
void Sudoku::swapNum(int x, int y) {
    int i, j;
    for(i = 0; i < mapSide; i++) {
        for(j = 0; j < mapSide; j++) {
            if(map[i][j] == x)
                map[i][j] = -1;
            if(map[i][j] == y)
                map[i][j] = -2;
        }
    }
    for(i = 0; i < mapSide; i++) {
        for(j = 0; j < mapSide; j++) {
            if(map[i][j] == -1)
                map[i][j] = y;
            if(map[i][j] == -2)
                map[i][j] = x;
        }
    }
}

void Sudoku::swapRow(int x, int y) {
    int i, j, temp;
    for(i = 0; i < blockSide; i++) {
        for(j = 0; j < mapSide; j++) {
            temp = map[i + x * blockSide][j];
            map[i + x * blockSide][j] = map[i + y * blockSide][j];
            map[i + y * blockSide][j] = temp;
        }
    }
}

void Sudoku::swapCol(int x, int y) {
    int i, j, temp;
    for(i = 0; i < mapSide; i++) {
        for(j = 0; j < blockSide; j++) {
            temp = map[i][j + x * blockSide];
            map[i][j + x * blockSide] = map[i][j + y * blockSide];
            map[i][j + y * blockSide] = temp;
        }
    }
}

void Sudoku::rotate(int x) {
    x %= 4;
    int i, j, k, temp[mapSide][mapSide];
    for(i = 0; i < x; i++) {
        for(j = 0; j < mapSide; j++) {
            for(k = 0; k < mapSide; k++) {
                temp[j][k] = map[j][k];
            }
        }
        for(j = 0; j < mapSide; j++) {
            for(k = 0; k < mapSide; k++) {
                map[k][mapSide - j - 1] = temp[j][k];
            }
        }
    }
}

void Sudoku::flip(int x) {
    int i, j, temp;
    if(x == 0) {
        for(i = 0; i < mapSide / 2; i++) {
            for(j = 0; j < mapSide; j++) {
                swap(map[i][j], map[mapSide - i - 1][j]);
            }
        }
    }
    if(x == 1) {
        for(i = 0; i < mapSide; i++) {
            for(j = 0; j < mapSide / 2; j++) {
                swap(map[i][j], map[i][mapSide - j - 1]);
            }
        }
    }
}

//Solve
void Sudoku::solve(int index) {
    if(ansNum == 2) return;
    int i, j, t = 0;
    if(index == blankSize) {
        ansNum++;
        if(ansNum == 1) {
            for(i = 0; i < mapSide; i++) {
                for(j = 0; j < mapSide; j++) {
                    ans[i][j] = map[i][j];
                }
            }
            return;
        }
        if(ansNum == 2) return;
    }
    int r = blank[index][0], c = blank[index][1], b = blockNum(r, c);
    for(i = 1; i <= mapSide; i++) {
        if(!row[r][i] && !col[c][i] && !block[b][i]) {
            if(!ansNum)
            map[r][c] = i;
            row[r][i]++;
            col[c][i]++;
            block[b][i]++;
            solve(index + 1);
            row[r][i] = 0;
            col[c][i] = 0;
            block[b][i] = 0;
        }
    }
    return;
}

int Sudoku::getAnsNum() {
    return ansNum;
}

void Sudoku::printAns() {
    int i, j;
    for(i = 0; i < mapSide; i++) {
        for(j = 0; j < mapSide; j++) {
            if(j != 8)
                printf("%d ", ans[i][j]);
            else
                printf("%d", ans[i][j]);
        }
        printf("\n");
    }
}
