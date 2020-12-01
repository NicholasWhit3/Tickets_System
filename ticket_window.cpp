#include "ticket_window.h"
#include "ticketbase.h"

Ticket_Window::Ticket_Window(TicketBase &ticketBase) : _ticketBase(ticketBase) 
{
std::cout << "Working in Ticket_Window::Ticket_Window..." << std::endl;
}

int Ticket_Window::getWindow_number() const
{
    return window_number;
}

void Ticket_Window::setWindow_number(int value)
{
    window_number = value;
}
