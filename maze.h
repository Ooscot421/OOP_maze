#ifndef MAZE_H
#define MAZE_H

using namespace std;
#include "block.h"

#include "player.h"
class Player;

const int LEVEL_NUM = 4;

const int BLOCK_SIZE = 3;

// Game message
void ALL_PASS();
void SHOW_LEVEL(int currentLevel);

class Maze {
private:
    vector<vector<Block*>> maze;
    vector<vector<char>> pixel;
    int nRow, nCol;
    int nKey = 0;

public:
    Maze(string input_filename);

    int get_nRow() const {return nRow;}
    int get_nCol() const {return nCol;}
    void printMaze(Player* player);
    Block* get_block(int row, int col) {return maze[row][col];}
};

#endif
