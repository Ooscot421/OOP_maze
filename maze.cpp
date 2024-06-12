#include <bits/stdc++.h>
#include "maze.h"
#include "wall.h"
#include "empty.h"
#include "goal.h"
#include <thread>
#include <chorono>
using namespace std;

// Timing control
void delay(int milliseconds) { std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds)); }


Maze::Maze(string input_filename)
{
    
    string str;
    int col;
    int row = 0;
    ifstream input_file;
    input_file.open(input_filename);
    
    vector<Block*> tmpBlockVec;
    Block* tmpBlock;
    while (getline(input_file, str)){
        row++;
        col = str.length();
        
        for(int i = 0; i < col; i++){
            
            if(str[i] == '0'){
                Empty *empty = new Empty();
                tmpBlock = empty;
                tmpBlockVec.push_back(tmpBlock);
            }
            else if(str[i] == '1'){
                Wall *wall = new Wall();
                tmpBlock = wall;
                tmpBlockVec.push_back(tmpBlock);
            }
            else if(str[i] == '2'){
                Goal *goal = new Goal();
                tmpBlock = goal;
                tmpBlockVec.push_back(tmpBlock);
            }
            else
                continue;
        }

        maze.push_back(tmpBlockVec);
        tmpBlockVec.clear();
    }

    input_file.close();
    nRow = row;
    nCol = col;

}

void Maze::printMaze(Player* player){
    system("clear");
    
    for (int i = 0; i < maze.size(); i++){
        for (int grid_r = 0; grid_r < BLOCK_SIZE; grid_r++){
            for (int j = 0; j < maze[i].size(); j++){
                for (int grid_c = 0; grid_c < BLOCK_SIZE; grid_c++){
                    if(i == player->get_player_row() && j == player->get_player_col())
                        cout << "\033[1;32m" << player->get_symbol()[0][grid_r][grid_c] << "\033[0m";
                    else{
                        switch(maze[i][j]->get_type()){
                            case tGoal:
                                cout << "\033[1;33m" << maze[i][j]->get_symbol()[0][grid_r][grid_c] << "\033[0m";
                            break;
                            
                            default:
                                cout << maze[i][j]->get_symbol()[0][grid_r][grid_c];
                        }

                        
                    }
                }
            }
            cout << endl;
        }
    }

}

void ALL_PASS() {
    for (int i = 3; i > 0; i--) {
        system("clear");
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "!!!           CONGRATULATIONS           !!!" << endl;
        cout << "!!!          YOU PASS ALL LEVEL         !!!" << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "Exiting in " << i << " seconds ..." << endl;
        delay(1000);
    }
    return;
}

void SHOW_LEVEL(int currentLevel) {
    for (int shine = 0; shine < 10; shine++) {
        system("clear");
        bool shineEnable = (shine % 2 == 0);

        // Row 1
        cout << "!!!";
        for (int i = 1; i <= LEVEL_NUM; i++) {
            if (i < LEVEL_NUM) cout << "!!!!!!!!!!";
            else               cout << "!!!!!!!!";
        }
        cout << "!!!" << endl;

        // Row 2
        cout << "!!!";
        for (int i = 1; i <= LEVEL_NUM; i++) {
            string msg = " LEVEL" + to_string(i) + " ";
            // Current level shining
            if (i == currentLevel && shineEnable) cout << "\033[1;32m" << msg << "\033[0m";
            else                                  cout << msg;
            // Intervals
            if (i < LEVEL_NUM) cout << "->";
        }
        cout << "!!!" << endl;

        // Row 3
        cout << "!!!";
        for (int i = 1; i <= LEVEL_NUM; i++) {
            if (i < LEVEL_NUM) cout << "!!!!!!!!!!";
            else               cout << "!!!!!!!!";
        }
        cout << "!!!" << endl;

        delay(200);
    }

    delay(1000);
}