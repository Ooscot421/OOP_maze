#ifndef PLAYER_H
#define PLAYER_H
#include "block.h"
using namespace std;

#include "maze.h"
class Maze;

class Player : public Block{
private:
    int player_row;
    int player_col;
    int key_Collected = 0;
    
public:
    Player(int startRow, int startCol);

    int get_player_row() const {return player_row;}
    int get_player_col() const {return player_col;}

    char get_direction();
    void move(char direction, const Maze* maze);
    void change_symbol();
    void player_touched() override{};   //Not need to implement this function because the player won't touch himself/herself 

};

#endif