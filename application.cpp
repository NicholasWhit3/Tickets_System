#include "application.h"
#include <iostream>

Application::Application() : _dataBase(*new Database()), airport(*new Airport(_dataBase)), ui(*new UI (_dataBase))
{
    std::cout << "The application is created. " << std::endl;
}

Application::~Application()
{
    delete &airport;
    delete &ui;
     std::cout << "The application is destroyed. " << std::endl;
}

int Application::run()
{
     std::cout << "The application is running. " << std::endl;

    while (get_menu_choice());
    return 0;
}

bool Application::get_menu_choice()
{
    std::string menu_choice = ui.main_menu();
    if(menu_choice == "4"){
    return false;
    }else if (menu_choice == "1"){
    buying_ticket();
    }else if (menu_choice == "2"){

    }else if (menu_choice == "3"){

    }
    return true;
}

void Application::buying_ticket()
{
    std::cout << "You bought the ticket " << std::endl;


}
