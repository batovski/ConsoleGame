#ifndef WAMPUS_H
#define WAMPUS_H
#include "Event.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Wampus : public Event
{

    public:
        Wampus();
        ~Wampus();
        void encounter(Player&);
        void Percept() override;
        void run();
};

#endif