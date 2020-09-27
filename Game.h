#ifndef GAME_H
#define GAME_H
#include "Event.h"
#include "Wampus.h"
#include "Gold.h"
#include "Bat.h"
#include "Pits.h"
#include "Room.h"
#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;

class Game
{
    private:
    Player player;
    Arrow* arrow;
    bool is_shooted = false;
    int spawn_position_x;
    int spawn_position_y;
    bool is_tacken = false;
    bool killed = false;
    bool debug;
    bool AI_mode = false;;
    int num_rooms;
    vector<vector<Room> > grid;
    
    
    public:
    Game();
    Game(int,string);
    ~Game();

    //Simplification
    bool Update(string&);
    void Player_Move(string&);
    void Player_Shoot(string&);
    void clear();
    bool endgame();
    //Handle Input
    bool handle_input(string&);
    void generate_grid();
    void print_grid();
    void print_inteface();
    //Player
    void interface();
    void move_player(string);
    void player_shoot();
    bool check_wall(int);
    void handle_event();
    void percept();
    void shoot(const string);
    void fly(int, int);
    void restore();
    //Wampus
    void move_Wampus(int, int);
    void check_Wampus(int,int,int,int);
    //Spawner
    void spawn_Gold();
    void spawn_Pits();
    void spawn_Bat();
    ////AI////
    void AI_move();
    void AI_shoot();
    void AI_collect();
    bool AI_mind();

};

#endif