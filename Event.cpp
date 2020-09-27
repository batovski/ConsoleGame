#include <iostream>
#include "Event.h"

using namespace std;

/*******************************************************************
** Functions: Event
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Event::Event()
{
    this->name = Event_Name::Empty;
}

/*******************************************************************
** Functions: Percept
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Event::Percept()
{

}
/*******************************************************************
** Functions: Event
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Event::~Event()
{

}
/*******************************************************************
** Functions: get_event_name
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
string Event::get_event_name()
{
    switch(name)
    {
        case Event_Name::Wampus :
        return "Wampus";

        case Event_Name::Bat :
        return "Bat";

        case Event_Name::Pits :
        return "Pits";

        case Event_Name::Gold :
        return "Gold";

        case Event_Name::Empty :
        return "Empty";
    }
}
/*******************************************************************
** Functions: set_name
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Event::set_name()
{
    name = Event_Name::Empty;
}
/*******************************************************************
** Functions: restore
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Event::restore()
{
    if(curent_name == "Gold")
        name = Event_Name::Gold;
    if(curent_name == "Wampus")
        name = Event_Name::Wampus;
}