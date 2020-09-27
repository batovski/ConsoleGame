#include "Player.h"
#include <iostream>

using namespace std;

/*******************************************************************
** Functions: Player
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Player::Player()
{
    num_arrows = 3;
    treasure_collected = false;
    alive = true;
}
/*******************************************************************
** Functions: ~Player
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Player::~Player()
{

}
/*******************************************************************
** Functions: move
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Player::move(int x, int y)
{
    position_x = x;
    position_y = y;
}
/*******************************************************************
** Functions: shoot
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
bool Player::shoot()
{
    if(num_arrows > 0)
    {
        num_arrows--;
        return true;
    }
    else
    {
        return false;
    }
}
/*******************************************************************
** Functions: display
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Player::display()
{
    cout<<"|    |^_^|   |";
}

//Getters
/*******************************************************************
** Functions: getters
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
int Player::get_position_x()
{
    return position_x;
}
int Player::get_position_y()
{
    return position_y;
}
bool Player::get_condition()
{
    return alive;
}
int Player::get_size()
{
    return max_size;
}
bool Player::get_collected()
{
    return treasure_collected;
}
int Player::get_arrows()
{
    return num_arrows;
}
///
/*******************************************************************
** Functions: Setters
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Player::set_size(int _size)
{
    max_size = _size;
}

///
/*******************************************************************
** Functions: die
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Player::die()
{
    alive = false;
}

/*******************************************************************
** Functions: collect
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Player::collect()
{
    treasure_collected = true;
}

/*******************************************************************
** Functions: clear
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Player::clear()
{
    num_arrows = 3;
    treasure_collected = false;
    alive = true;
    position_y = 0;
    position_x = 0;
}

