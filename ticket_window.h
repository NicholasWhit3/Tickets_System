#ifndef TICKET_WINDOW_H
#define TICKET_WINDOW_H
#include "ticketbase.h"
#include "ui.h"

class Ticket_Window
{
public:
    Ticket_Window(TicketBase& ticketBase);
    void find_tickets();
    void ticket_sale();
    int getWindow_number() const;
    void setWindow_number(int value);


private:
    int window_number;
    TicketBase& _ticketBase;

};

#endif // TICKET_WINDOW_H
