#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class Event
{
    protected:
    enum Event_Name{Wampus,Pits,Bat,Gold,Empty};
    Event_Name name = Event_Name::Empty;
    string curent_name = "";

    public:
        Event();
        virtual ~Event();
        virtual void encounter(Player&) = 0;
        virtual void Percept();
        void change_postion();
        string get_event_name();
        void set_name();
        void restore();
};

#endif