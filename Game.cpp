#include <iostream>
#include "Game.h"
#include <chrono>
#include <thread>

using namespace std;

/*******************************************************************
** Functions: Game
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Game::Game()
{
    arrow = NULL;
}

/*******************************************************************
** Functions: Game
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Game::Game(int number, string debug)
{   
    if(debug == "true")
    this->debug = true;
    else if(debug == "false")
    this->debug = false;
    else if(debug == "AI")
    AI_mode = true;
    num_rooms = number;
    player.set_size(number);
    for (int i = 0; i < num_rooms; i++)
    {
        vector<Room> row_vec;
        for (int j = 0; j < num_rooms; j++)
        {
            Room room;
            row_vec.push_back(room);
        }
        grid.push_back(row_vec);
    }
}

/*******************************************************************
** Functions: ~Game
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
Game::~Game()
{
}

//Simplification
/*******************************************************************
** Functions: Update
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
bool Game::Update(string& temp_string)
{
    if(debug)
        print_grid();
    else if(!debug)
        print_inteface();
    handle_event();
    if (!player.get_condition())
        return true;
    if (killed && is_tacken && player.get_position_x() == spawn_position_x && player.get_position_y() == spawn_position_y)
        return true;
    getline(cin, temp_string);
    handle_input(temp_string);
    return false;
}

/*******************************************************************
** Functions: Player_Move
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::Player_Move(string& temp_string)
{
    move_player(temp_string);
    if(debug)
        print_grid();
    else if(!debug)
        print_inteface();
    percept();
    handle_event();
}

/*******************************************************************
** Functions: Player_shoot
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::Player_Shoot(string& temp_string)
{
    cout << "Pint the direction to shoot (W,A,S,D)" << endl;
    getline(cin, temp_string);
    handle_input(temp_string);
    shoot(temp_string);
}

/*******************************************************************
** Functions: endgame
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
bool Game::endgame()
{
    string temp_string;
    cout << "Do you want to Generate new map? 1 - yes 2 - no 3 - exit" << endl;
    getline(cin, temp_string);
    if (temp_string == "1")
    {
        clear();
        is_tacken = false;
        killed = false;
        player.clear();
        generate_grid();
    }
    else if (temp_string == "2")
    {
        restore();
        is_tacken = false;
        killed = false;
        player.clear();
        player.move(spawn_position_x, spawn_position_y);
    }
    else
    {
        return true;
    }
    return false;
}
//There is no reason to separete this function, this just make things harder
////////////////////////////////////////////////////////////////////////

/*******************************************************************
** Functions: Generate Grid
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::generate_grid()
{
    //Wampus
    int num_rom;
    int num_colon;
    move_Wampus(0,0);
    //Gold
    spawn_Gold();
    //Pits
    spawn_Pits();
    //Bat
    spawn_Bat();
    //Player spawn
    while (true)
    {
        num_rom = rand() % num_rooms;
        num_colon = rand() % num_rooms;
        if (grid[num_rom][num_colon].get_event_name() == "Empty")
        {
            player.move(num_rom, num_colon);
            spawn_position_x = num_rom;
            spawn_position_y = num_colon;
            break;
        }
    }
}

/*******************************************************************
** Functions: Print_grid
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::print_grid()
{
    for (int i = 0; i < num_rooms; i++)
    {
        for (int l = 0; l < num_rooms; l++)
            cout << "-----------";
        cout << endl;
        for (int j = 0; j < num_rooms; j++)
        {
            if (grid[i][j].get_event_name() == "Wampus")
                cout << "|   "<< " (*_*) "<< "  |";
            else if (is_shooted && i == arrow->x && j == arrow->y)
                cout << "|   "<< " * "<< "  |";
            else if (i == player.get_position_x() && j == player.get_position_y())
                player.display();
            else if (grid[i][j].get_event_name() == "Bat")
                cout << "|   "<< " ^+^ "<< "  |";
            else if (grid[i][j].get_event_name() == "Gold")
                cout << "|   "<< " $$$ " << "  |";
            else if (grid[i][j].get_event_name() == "Pits")
                cout << "|   "<< " ( ) " << "  |";
            else
            {
                cout << "|   ---  |";
            }
        }
        cout << endl;
        for (int l = 0; l < num_rooms; l++)
            cout << "-----------";
        cout << endl;
    }
    cout<<endl;
}
//This is print function, everything should be on the same level of abstraction

/*******************************************************************
** Functions: Print Interface
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::print_inteface()
{
    for (int i = 0; i < num_rooms; i++)
    {
        for (int l = 0; l < num_rooms; l++)
            cout << "-----------";
        cout << endl;
        for (int j = 0; j < num_rooms; j++)
        {
            if (is_shooted && i == arrow->x && j == arrow->y)
                cout << "|   "<< " * "<< "  |";
            else if (i == player.get_position_x() && j == player.get_position_y())
                player.display();
            else
            {
                cout << "|   ---  |";
            }
        }
        cout << endl;
        for (int l = 0; l < num_rooms; l++)
            cout << "-----------";
        cout << endl;
    }
    cout<<endl;
}

/*******************************************************************
** Functions: Handle Input
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
bool Game::handle_input(string &input)
{
    while (true)
    {
        if (input == "w" || input == "W" || input == "A" || input == "a" || input == "S" || input == "s" || input == "D" || input == "d" || input == " ")
        {
            return true;
        }
        else
        {
            cout << "Prints W,A,S,D" << endl;
            getline(cin, input);
        }
    }
}

////////////////////////////Player Options
/*******************************************************************
** Functions: interface
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::interface()
{
    while(true)
    {
        string temp_string;
        cout << "Welcome to my game! \nIn order to move use W,A,S,D\n"
            << "In order to shoot press SPACEBAR and navigate your shoot direction"
            << "using W,A,S,D" << endl;
        while (player.get_condition())
        {
            if(!AI_mode)
            {
                if(Update(temp_string))
                    break;
                if (temp_string != " ") //if true - move
                {
                    Player_Move(temp_string);
                }
                else //False - shoot
                {
                    Player_Shoot(temp_string);
                }
            }
            else
            {
                if(AI_mind())
                    break;
            }
        }
        if (is_tacken && killed && player.get_condition())
        {
            cout << "\nYou win!" << endl;
            break;
        }
        else
        {
           if(endgame())
            break;
        }
    }
}
//This logic of the whole game, it should be on the same level of abstraction

/*******************************************************************
** Functions: move_player
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::move_player(string direction)
{
    if (direction == "w" || direction == "W")
    {
        if (check_wall(player.get_position_x() - 1))
            player.move(player.get_position_x() - 1, player.get_position_y());
    }
    else if (direction == "A" || direction == "a")
    {
        if (check_wall(player.get_position_y() - 1))
            player.move(player.get_position_x(), player.get_position_y() - 1);
    }
    else if (direction == "S" || direction == "s")
    {
        if (check_wall(player.get_position_x() + 1))
            player.move(player.get_position_x() + 1, player.get_position_y());
    }
    else if (direction == "D" || direction == "d")
    {
        if (check_wall(player.get_position_y() + 1))
            player.move(player.get_position_x(), player.get_position_y() + 1);
    }
}

/*******************************************************************
** Functions: check wall
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
bool Game::check_wall(int _position)
{
    if (_position >= num_rooms || _position < 0)
        return false;
    return true;
}

/*******************************************************************
** Functions: handle event
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::handle_event()
{
    int x = player.get_position_x();
    int y = player.get_position_y();
    if (grid[x][y].get_event_name() != "Empty")
    {
        grid[x][y].encounter(player);
    }
    if (player.get_collected())
        is_tacken = true;
}

/*******************************************************************
** Functions: percept
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::percept()
{
    int x = player.get_position_x();
    int y = player.get_position_y();
    if ((x + 1) < num_rooms && grid[x + 1][y].get_event_name() != "Empty")
    {
        grid[x + 1][y].perception();
    }
    if ((x - 1) >= 0 && grid[x - 1][y].get_event_name() != "Empty")
    {
        grid[x - 1][y].perception();
    }
    if ((y + 1) < num_rooms && grid[x][y + 1].get_event_name() != "Empty")
    {
        grid[x][y + 1].perception();
    }
    if ((y - 1) >= 0 && grid[x][y - 1].get_event_name() != "Empty")
    {
        grid[x][y - 1].perception();
    }
}

/*******************************************************************
** Functions: Shoot
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::shoot(const string direction)
{
    if (direction == "w" || direction == "W")
    {
        fly(-1, 0);
    }
    else if (direction == "A" || direction == "a")
    {
        fly(0, -1);
    }
    else if (direction == "S" || direction == "s")
    {
        fly(1, 0);
    }
    else if (direction == "D" || direction == "d")
    {
        fly(0, 1);
    }
}

/*******************************************************************
** Functions: fly
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::fly(int x, int y)
{
    if (player.get_arrows() != 0)
    {
        arrow = new Arrow;
        arrow->x = player.get_position_x();
        arrow->y = player.get_position_y();
        player.shoot();
        is_shooted = true;
        for (int i = 0; i <= 3; i++)
        {
            if(debug)
                print_grid();
            else if(!debug)
                print_inteface();
            if (arrow->x >= 0 && arrow->x < num_rooms && arrow->y >= 0 && arrow->y < num_rooms)
            {
                if (grid[arrow->x][arrow->y].get_event_name() == "Wampus")
                {
                    grid[arrow->x][arrow->y].empty();
                    killed = true;
                    cout << "You have killed Wampus!!!" << endl;
                    break;
                }
                check_Wampus(arrow->x,arrow->y,x,y);
                arrow->x += x;
                arrow->y += y;
            }
            else
            {
                break;
            }
            this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        is_shooted = false;
        cout << endl<< "Arrows left: " << player.get_arrows() << endl;
        delete arrow;
        arrow = nullptr;
    }
}
//This is arrow logic, to avoid missundrestanding, and for easy debuging I have left it here.

/*******************************************************************
** Functions: clear
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::clear()
{
    for(int i = 0; i < num_rooms; i++)
    {
        for (int j = 0; j < num_rooms; j++)
        {
            grid[i][j].clear();
        }
    }
}

/*******************************************************************
** Functions: restore
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::restore()
{
    for(int i = 0; i < num_rooms; i++)
    {
        for (int j = 0; j < num_rooms; j++)
        {
            if(grid[i][j].get_event_name() == "Empty")
            {
                grid[i][j].restore();
            }
        }
    }
}

/*******************************************************************
** Functions: move_wampus
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::move_Wampus(int x, int y)
{
    while (true)
    {
       int num_rom = rand() % num_rooms;
       int num_colon = rand() % num_rooms;
        if (grid[num_rom][num_colon].get_event_name() == "Empty")
        {
            grid[num_rom][num_colon].clear();
            grid[x][y].clear();
            grid[num_rom][num_colon].create_Wampus();
            break;
        }
    }
}

/*******************************************************************
** Functions: check wampus
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::check_Wampus(int x, int y,int x_dir, int y_dir)
{
    int chance = rand()%100;
    if(x_dir == 0)
    {
        if ((x + 1) < num_rooms && grid[x + 1][y].get_event_name() == "Wampus")
        {
            if(chance < 76)
            move_Wampus(x+1,y);
        }
        else if ((x - 1) >= 0 && grid[x - 1][y].get_event_name() == "Wampus")
        {
            if(chance < 76)
            move_Wampus(x-1,y);
        }
    }
    else if(y_dir == 0)
    {
        if ((y + 1) < num_rooms && grid[x][y + 1].get_event_name() == "Wampus")
        {
            if(chance < 76)
            move_Wampus(x,y+1);
        }
        else if ((y - 1) >= 0 && grid[x][y - 1].get_event_name() == "Wampus")
        {
            if(chance < 76)
            move_Wampus(x,y-1);
        }
    }
}
////////////////////////////////////////////////////////////// Spawner
/*******************************************************************
** Functions: spawn bat
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::spawn_Bat()
{
    int spawned = 0;
    while (true)
    {
        int num_rom = rand() % num_rooms;
        int num_colon = rand() % num_rooms;
        if (grid[num_rom][num_colon].get_event_name() == "Empty")
        {
            grid[num_rom][num_colon].create_Bat();
            spawned++;
            if (spawned == 2)
            {
                break;
            }
        }
    }
}

/*******************************************************************
** Functions: spawn gold
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::spawn_Gold()
{
    while (true)
    {
        int num_rom = rand() % num_rooms;
        int num_colon = rand() % num_rooms;
        if (grid[num_rom][num_colon].get_event_name() == "Empty")
        {
            grid[num_rom][num_colon].create_Gold();
            break;
        }
    }
}

/*******************************************************************
** Functions: spawn pits
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::spawn_Pits()
{
    int spawned = 0;
    while (true)
    {
        int num_rom = rand() % num_rooms;
        int num_colon = rand() % num_rooms;
        if (grid[num_rom][num_colon].get_event_name() == "Empty")
        {
            grid[num_rom][num_colon].create_Pits();
            spawned++;
            if (spawned == 2)
            {
                break;
            }
        }
    }
}

/*******************************************************************
** Functions: AiI move
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::AI_move()
{
    int chance = rand()% 100;
    if(chance < 26)
    {
        if (check_wall(player.get_position_x() - 1) && grid[player.get_position_x() - 1][player.get_position_y()].get_event_name()=="Empty")
        {
                player.move(player.get_position_x() - 1, player.get_position_y());
        }
    }
    if(chance < 51 && chance > 25)
    {
        if (check_wall(player.get_position_y() - 1) && grid[player.get_position_x()][player.get_position_y()-1].get_event_name()=="Empty")
        {
                player.move(player.get_position_x(), player.get_position_y() - 1);
        }
    }
    if(chance < 76 && chance > 50)
    {
        if (check_wall(player.get_position_x() + 1) && grid[player.get_position_x()+1][player.get_position_y()].get_event_name()=="Empty")
        {
                player.move(player.get_position_x() + 1, player.get_position_y());
        }
    }
    if(chance > 75)
    {
        if (check_wall(player.get_position_y() + 1) && grid[player.get_position_x()][player.get_position_y()+1].get_event_name()=="Empty")
        {
                player.move(player.get_position_x(), player.get_position_y() + 1);
        }
    }
    this_thread::sleep_for(std::chrono::milliseconds(500));
}

/*******************************************************************
** Functions: AI shoot
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::AI_shoot()
{
    if (check_wall(player.get_position_x() - 1) && grid[player.get_position_x() - 1][player.get_position_y()].get_event_name()=="Wampus")
    {
           fly(-1,0);
           this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    else if (check_wall(player.get_position_y() - 1) && grid[player.get_position_x()][player.get_position_y()-1].get_event_name()=="Wampus")
    {
           fly(0,-1);
           this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    else if (check_wall(player.get_position_x() + 1) && grid[player.get_position_x()+1][player.get_position_y()].get_event_name()=="Wampus")
    {
           fly(1,0);
           this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    else if (check_wall(player.get_position_y() + 1) && grid[player.get_position_x()][player.get_position_y()+1].get_event_name()=="Wampus")
    {
           fly(0,1);
           this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
}

/*******************************************************************
** Functions: AI collect
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
void Game::AI_collect()
{
        if (check_wall(player.get_position_x() - 1) && grid[player.get_position_x() - 1][player.get_position_y()].get_event_name()=="Gold")
        {
            player.move(player.get_position_x() - 1,player.get_position_y());
            player.collect();
            this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        else if (check_wall(player.get_position_y() - 1) && grid[player.get_position_x()][player.get_position_y()-1].get_event_name()=="Gold")
        {
            player.move(player.get_position_x(),player.get_position_y()-1);
            player.collect();
            this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        else if (check_wall(player.get_position_x() + 1) && grid[player.get_position_x()+1][player.get_position_y()].get_event_name()=="Gold")
        {
            player.move(player.get_position_x() + 1,player.get_position_y());
            player.collect();
            this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        else if (check_wall(player.get_position_y() + 1) && grid[player.get_position_x()][player.get_position_y()+1].get_event_name()=="Gold")
        {
            player.move(player.get_position_x(),player.get_position_y()+1);
            player.collect();
            this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
}
/*******************************************************************
** Functions: AI mind
** Description: fun that return values of parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: retutned value
*******************************************************************/
bool Game::AI_mind()
{
    print_inteface();
    AI_move();
    print_inteface();
    percept();
    handle_event();
    AI_shoot();
    AI_collect();
    if (killed && is_tacken && player.get_position_x() == spawn_position_x && player.get_position_y() == spawn_position_y)
        return true;
    return false;
}