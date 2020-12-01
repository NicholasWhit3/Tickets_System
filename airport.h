#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
#include "ticketbase.h"
#include "ticket_window.h"
#include "ticket.h"
#include <vector>

class Airport
{
public:
    Airport(Database& dataBase);
    ~Airport();

    std::vector  <std::vector<std::string>> get_tickets_from_company();

    std::string airport_name() const;
    void setAirport_name(const std::string &airport_name);

    std::string airport_location() const;
    void setAirport_location(const std::string &airport_location);

    float temperature_outside() const;
    void setTemperature_outside(float temperature_outside);

    bool parking_place() const;
    void setParking_place(bool parking_place);

    bool taxi() const;
    void set_Taxi(bool taxi);

private:
    std::string _airport_name = "";
    std::string _airport_location = "";
    float _temperature_outside = 0.0;
    bool _parking_place;
    bool _taxi;
    Database& _dataBase;
    TicketBase& _ticket_base;                          
    Ticket_Window& _ticket_window;
    std::string gen_destination();

};

#endif // AIRPORT_H
