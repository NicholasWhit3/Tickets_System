#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "database.h"
#include <vector>
#include <map>
class Ticket
{
public:
    Ticket();
    Ticket(int number, std::string customer_full_name,  std::string destination, std::string departure_time, std::string arrival_time,
               std::string seat_class, std::string price, std::string buying_time );

    std::string number()const ;
    void setNumber(const std::string number);

//    bool save(Database& db);
    std::string tickets_buying_time(std::string other);

    std::string price()const ;
    void setPrice(const std::string &price);

    std::string seat_class()const ;
    void setSeat_class(const std::string &seat_class);

    std::string departure_time()const ;
    void setDeparture_time(const std::string &departure_time);

    std::string arrival_time()const ;
    void setArrival_time(const std::string &arrival_time);

    std::string customer_full_name()const ;
    void setCustomer_full_name(const std::string &customer_full_name);

    std::string buying_time()const ;
    void setBuying_time(const std::string &buying_time);

    std::string destination() const;
    void setDestination(const std::string &destination);

    std::string load(std::string other);

    void print();

    std::map<std::string, std::string> data() const;
    void setData(const std::map<std::string, std::string> &data);

private:
    std::map <std::string, std::string> _data = {
        {"number", "0"},
        {"price","0"},
        {"destination", "0"},
        {"departure_time", "0"},
        {"arrival_time", "0"},
        {"customer_full_name", "0"},
        {"buying_time", "0"},
        {"seat_class", "0"}
        };
   int ticket_status;

   //flight_number




//    int _number = 0;
//    std::string _price = "";
//    std::string _destination = "";
//    std::string _seat_class = "00A";
//    std::string _departure_time = "";
//    std::string _arrival_time = "";
//    std::string _customer_full_name = "";
//    std::string _buying_time = "";


};
            // HW func LOAD
#endif // TICKET_H
