#ifndef PITS_H
#define PITS_H
#include "Event.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Pits : public Event
{
    private:

    public:
        Pits();
        ~Pits();
        void encounter(Player&);
        void Percept() override;
};

#endif