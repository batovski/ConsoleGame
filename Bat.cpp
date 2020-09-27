#include <iostream>
#include "Bat.h"
#include "Event.h"
#include "Player.h"

using namespace std;

/*******************************************************************
** Functions: Constructor
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Bat::Bat()
{
   this->name = Event_Name::Bat;
}

/*******************************************************************
** Functions: Encounter
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Bat::encounter(Player& player)
{
    int num_rom = rand()% player.get_size();
    int num_colon = rand()% player.get_size();
    player.move(num_rom,num_colon);
    cout<<"You have been moved by bat!"<<endl;
}

/*******************************************************************
** Functions: Percept
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Bat::Percept()
{
    cout <<"You hear wings flapping"<<endl;
}

/*******************************************************************
** Functions: Bat
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Bat::~Bat()
{

}