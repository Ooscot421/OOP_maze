#include <bits/stdc++.h>
#include "player.h"
using namespace std;

Player::Player(int startRow, int startCol) : Block(), player_row(startRow), player_col(startCol){
    symbol = {
                {   
                    {' ', 'O', ' '}, 
                    {'/', '|', '\\'}, 
                    {'/', ' ', '\\'} 
                }
            };
    type = tPlayer;
}

void Player::move(char direction, const Maze* maze){
    int nextRow = player_row, nextCol = player_col;
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
            return;
    }

    if (nextRow >= 0 && nextRow < maze->get_nRow() && nextCol >= 0 && nextCol < maze->get_nCol()) {
        player_row = nextRow;
        player_col = nextCol;
    }

    return;
}

void Player::change_symbol(){
    //write by yourself
}

char Player::get_direction() {
    while(true) {
        system("stty raw");
        char c = getchar();
        system("stty cooked");

        switch (c) {
            case 'W':
            case 'w':
                return 'U';
            case 'S':
            case 's':
                return 'D';
            case 'A':
            case 'a':
                return 'L';
            case 'D':
            case 'd':
                return 'R';
            case 'E':
            case 'e':
                system("stty cooked");
                system("clear");
                exit(0);
            default:
                continue;
        }
    }
}

