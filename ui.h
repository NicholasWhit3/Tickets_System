#ifndef UI_H
#define UI_H
#include "database.h"

class UI
{
public:
    UI(Database& database);
    ~UI();

    std::string main_menu();
    std::string find_ticket_dialog();


private:
Database& _database;

};



#endif // UI_H
