#ifndef BAT_H
#define BAT_H
#include "Event.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Bat : public Event
{
    public:
        Bat();
        ~Bat();
        void encounter(Player&);
        void Percept() override;
};

#endif