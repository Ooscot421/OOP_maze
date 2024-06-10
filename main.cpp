#include <bits/stdc++.h>
#include "maze.h"
#include "player.h"
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

            player->move(direction, maze);

            maze->printMaze(player);
        }

        delete maze;
        delete player;
    }

    ALL_PASS();
    system("clear");
    return 0;
}
