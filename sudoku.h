#ifndef SUDOKU_H
#define SUDOKU_H

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

#include <vector>
using namespace std;

class Sudoku {
  public:
    static const int blockSide = 3;
    static const int mapSide = 9;

  private:
    int map[mapSide][mapSide];
    int ans[mapSide][mapSide];
    int ansNum;
    int row[mapSide][mapSide + 1] = {0};
    int col[mapSide][mapSide + 1] = {0};
    int block[mapSide][mapSide + 1] = {0};
    int blank[1000][2];
    int blankSize;

  public:
    Sudoku();
    int blockNum(int r, int c);
    void setSudoku(int input[][mapSide]);
    void printMap();

    // transform
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);

    // solve
    void solve(int index);
    int getAnsNum();
    void printAns();
};

#endif // SUDOKU_H
