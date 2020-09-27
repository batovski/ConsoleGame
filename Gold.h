#ifndef GOLD_H
#define GOLD_H
#include "Event.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Gold : public Event
{

    public:
        Gold();
        ~Gold();
        void encounter(Player&);
        void Percept() override;
};

#endif