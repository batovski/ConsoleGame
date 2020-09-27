#include <iostream>
#include "Wampus.h"
#include "Player.h"

using namespace std;

/*******************************************************************
** Functions: Wampus
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Wampus::Wampus()
{
   this->name = Event_Name::Wampus;
   curent_name = "Wampus";
}

/*******************************************************************
** Functions: Encounter
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Wampus::encounter(Player& player)
{
    player.die();
    cout<<"You have been killed by Wampus!"<<endl;
}

/*******************************************************************
** Functions: Percept
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Wampus::Percept()
{
    cout <<"You smell a terrible stench"<<endl;
}

/*******************************************************************
** Functions: Run
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Wampus::run()
{
    cout<<"I am running to another room"<<endl;
}

/*******************************************************************
** Functions: ~Wampus
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Wampus::~Wampus()
{
    
}