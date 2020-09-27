#include <iostream>
#include "Room.h"

using namespace std;

/*******************************************************************
** Functions: Room
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Room::Room()
{
    event = nullptr;
}

/*******************************************************************
** Functions: ~Room
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Room::~Room()
{
    delete event;
    event = nullptr;
}

/*******************************************************************
** Functions: crete_wampus
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Room::create_Wampus()
{
    event = new Wampus;
}
/*******************************************************************
** Functions: create Gold
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Room::create_Gold()
{
    event = new Gold;
}

/*******************************************************************
** Functions: create bat
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Room::create_Bat()
{
    event = new Bat;
}
/*******************************************************************
** Functions: create pits
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Room::create_Pits()
{
    event = new Pits;
}
/*******************************************************************
** Functions: encounter
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Room::encounter(Player& player)
{
    event->encounter(player);
}

/*******************************************************************
** Functions: perception
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Room::perception()
{
    event->Percept();
}

/*******************************************************************
** Functions: get name
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
string Room::get_event_name()
{
    if(event==nullptr)
        return "Empty";
    return event->get_event_name();  
}

/*******************************************************************
** Functions: clear
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Room::clear()
{
    if(event != NULL)
    {
        delete event;
        event = nullptr;
    }
}

/*******************************************************************
** Functions: empty
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Room::empty()
{
    event->set_name();
}

/*******************************************************************
** Functions: restore
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Room::restore()
{
    if(event!= nullptr)
        event->restore();
}