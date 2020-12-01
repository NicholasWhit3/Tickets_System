#include "ui.h"
#include <iostream>
#include "database.h"
#include <vector>
#include <fstream>

UI::UI(Database& database) : _database(database)
{
    std::cout << "Create UI..." << std::endl;
}

UI::~UI()
{
    std::cout << "Deleting UI..." << std::endl;
}

std::string UI::main_menu()
{

    std::vector <std::string> menu;
    std::string str;
    std::ifstream fin;
    std::vector <std::string> temps;

    _database.load_table("Menu.txt", menu);
    for(auto menuIteam :  menu)
    {
        std::cout << menuIteam << std::endl;
    }


    std::string choice;
    std::cout << ">> ";
    std::cin >> choice;

    return choice;
}
