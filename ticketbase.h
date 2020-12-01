#ifndef TICKETBASE_H
#define TICKETBASE_H
#include <vector>
#include "ticket.h"

class TicketBase
{
public:
    TicketBase(Database& database);
    ~TicketBase();

    void create_ticket(std::vector <std::vector<std::string>> tickets);
    void sale_ticket();
    static unsigned long long getTicketNumber();
    static void setTicketNumber(unsigned long long value);
    //find ticket

private:
    std::vector <Ticket> _ticket;
    Database& _dataBase;
    static unsigned long long ticketNumber;
};

#endif // TICKETBASE_H
