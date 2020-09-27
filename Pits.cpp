#include <iostream>
#include "Pits.h"
#include "Event.h"

using namespace std;

/*******************************************************************
** Functions: Pits
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Pits::Pits()
{
    this->name = Event_Name::Pits;
}

/*******************************************************************
** Functions: Encounter
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Pits::encounter(Player& player)
{
    player.die();
    cout<<"You fell into bottomless pit!"<<endl;
}

/*******************************************************************
** Functions: Percept
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Pits::Percept()
{
    cout <<"You feel a breeze"<<endl;
}

/*******************************************************************
** Functions: Pits
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Pits::~Pits()
{

}
