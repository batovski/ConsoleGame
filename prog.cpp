/***********************************************************
 * ** Program: assign4_Wampus.cpp
 * ** Authors: Danila Batov
 * ** Date: 05/23/2020
 * ** Description: Wampus game
 * ** Input: NA
 * ** Output: menu interface
 * ***********************************************************/
#include <iostream>
#include "Event.h"
#include "Game.h"
#include "Room.h"
#include "Wampus.h"
#include "Gold.h"
#include "Bat.h"
#include "Pits.h"
#include <stdlib.h>
#include <ctime> 

using namespace std;

int main(int argc, char* argv[])
{
   srand(time(NULL));
   if (argv[1]== NULL || argv[2] == NULL && argv[3]== NULL)
	{
		cout << "Error!" << endl;
		return 1;
	}
    else
    {
        string number = argv[1];
        string debug = argv[2];
        if(atoi(number.c_str())< 4 || (debug != "true"&& debug != "false" && debug != "AI"))
        {
            cout<<"Invalid program inputs!"<<endl;
            return 1;
        }
        Game game(atoi(number.c_str()),debug);
        game.generate_grid();
        game.interface();
    }
    return 0;
}