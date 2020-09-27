#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player
{
    private:
    
    int position_x;
    int position_y;

    int max_size;
    
    int num_arrows;
    bool treasure_collected;
    bool alive;

    public:
    Player();
    ~Player();
    void move(int, int);
    bool shoot();
    void display();

    int get_position_x();
    int get_position_y();
    bool get_condition();
    bool get_collected();
    int get_arrows();

    int get_size(); 
    void set_size(int);

    void die();
    void collect();
    void clear();
};
struct Arrow
{
    int x;
    int y;
};

#endif