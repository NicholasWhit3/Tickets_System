#ifndef APPLICATION_H
#define APPLICATION_H
#include "ui.h"
#include "airport.h"
#include "ticketbase.h"
#include "database.h"

class Application
{
public:
    Application();
    ~Application();
    int run();
    bool get_menu_choice();
    // functions for menu
    void buying_ticket();
    //make clear code

private:
    Database& _dataBase;
    Airport& airport;
    UI& ui;

};


#endif // APPLICATION_H
