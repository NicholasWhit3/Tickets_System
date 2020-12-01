#include "ticketbase.h"
#include "database.h"
#include <map>


unsigned long long TicketBase :: ticketNumber = 0;

TicketBase::TicketBase(Database& database) : _dataBase(database)
{
    std::cout << "Create TicketBase::TicketBase..." << std::endl;

}

TicketBase::~TicketBase()
{

}

void TicketBase::create_ticket(std::vector <std::vector<std::string>> tickets)
{

    std::cout << "Working in TicketBase::create_ticket..." << std::endl;
    if(ticketNumber == 0)
    {
        Ticket ticket;
        std::vector <std::string> header;
        for(auto& d : ticket.data() )
        {
            header.push_back(d.first);
        }
        _dataBase.create_table("Ticket.txt", header);
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < std::stoi(tickets[i][5]); j++)
        {
            std::string ticket_class =  " ";
            ticket_class[0] = i + 'A';
            Ticket* ticket = new Ticket(ticketNumber++, " ",  tickets[i][1], tickets[i][2],tickets[i][3],
                                    ticket_class, tickets[i][4], " ");
            _ticket.push_back(*ticket);

            std::vector <std::string> value;
            for(auto& d : ticket->data() )
            {
                value.push_back(d.second);
            }
            _dataBase.insert_raw("Ticket.txt", value);

        }
    }
}


unsigned long long TicketBase::getTicketNumber()
{
    return ticketNumber;
}

void TicketBase::setTicketNumber(unsigned long long value)
{
    ticketNumber = value;
}
