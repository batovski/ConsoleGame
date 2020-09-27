#ifndef ROOM_H
#define ROOM_H
#include "Event.h"
#include "Wampus.h"
#include "Gold.h"
#include "Player.h"
#include "Bat.h"
#include "Pits.h"
#include <iostream>
using namespace std;

class Room
{
    private:
    Event* event;

    public:
    Room();
    ~Room();
    void create_Wampus();
    void create_Gold();
    void create_Bat();
    void create_Pits();
    void encounter(Player&);
    void perception();
    void clear();
    void empty();
    void restore();
    string get_event_name();
};

#endif