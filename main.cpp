#include <bits/stdc++.h>
#include "maze.h"
#include "player.h"
#include "block.h"
using namespace std;

int main(int argc, char** argv){

    for (int level = 1; level <= LEVEL_NUM; level++) {
        SHOW_LEVEL(level);

        
        string input_filename("maze" + to_string(level) + ".txt");

        Maze* maze = new Maze(input_filename);
        Player* player = new Player(1, 1);
        
        
        //Write your own code to generate the keys, obstacle, and ...

        maze->printMaze(player);

        while(true) {   //Condition for ending the game of this level. Write your own function to replace "true"
            char direction = player->get_direction();
            cout << "Main->direction = " << direction << endl;
            //Codes for the player touching different types of block. Use the function player_touched() to implement
            int nextRow = player->get_player_row(), nextCol = player->get_player_col();
            switch (direction) {
                case 'U':
                    nextRow -= 1;
                    break;
                case 'D':
                    nextRow += 1;
                    break;
                case 'L':
                    nextCol -= 1;
                    break;
                case 'R':
                    nextCol += 1;
                    break;
                default:
                    return 0;
            }
            if (nextRow >= 0 && nextRow < maze->get_nRow() && nextCol >= 0 && nextCol < maze->get_nCol()) 
            {
                Block* nextBlock = maze->get_block(nextRow, nextCol);
                if (nextBlock->get_type() == tWall) {
                    nextBlock->player_touched();
                }
                else if (nextBlock->get_type() == tGoal) {
                    break;
                }
                else {
                    player->move(direction, maze);
                }
            }
            maze->printMaze(player);
        }

        delete maze;
        delete player;
    }

    ALL_PASS();
    system("clear");
    return 0;
}
