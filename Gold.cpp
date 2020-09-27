#include <iostream>
#include "Gold.h"

using namespace std;

/*******************************************************************
** Functions: Constructor
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Gold::Gold()
{
   this->name = Event_Name::Gold;
   curent_name = "Gold";
}

/*******************************************************************
** Functions: Encounter
** Description: fun that return values of parameters
** Parameters: Player
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Gold::encounter(Player& player)
{
    player.collect();
    name = Event_Name::Empty;
    cout<<"You have collected the gold!"<<endl;
}

/*******************************************************************
** Functions: Percept
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Void
*******************************************************************/
void Gold::Percept()
{
    cout <<"You see a glimmer nearby"<<endl;
}
/*******************************************************************
** Functions: Distructor
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: NA
*******************************************************************/
Gold::~Gold()
{

}
