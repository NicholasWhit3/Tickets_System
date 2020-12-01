#include "ticket.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Ticket::Ticket() : ticket_status (0)
{

}

Ticket::Ticket(int number, std::string customer_full_name,  std::string destination, std::string departure_time, std::string arrival_time,
               std::string seat_class, std::string price, std::string buying_time  ) : ticket_status (0)
{

    _data.at("customer_full_name") = customer_full_name;
    _data.at("departure_time") = departure_time;
    _data.at("price") = price;
    _data.at("buying_time") = buying_time;
    _data.at("number") = std::to_string(number);
    _data.at("destination") = destination;
    _data.at("arrival_time") = arrival_time;
    _data.at("seat_class") = seat_class;

}

std::string Ticket::number()const
{
    return  _data.at("number");
}

void Ticket::setNumber(const std::string number)
{
    this->_data.at("number") = number;
}

//bool Ticket::save(Database& db)
//{
//    std::vector <std::string> header;
//    std::vector <std::string> data;
//    for(auto p : _data)
//    {
//        header.push_back(p.first);
//        data.push_back(p.second);
//    }
//    db.insert_raw("Ticket", data);
//    return  true;
//}

 std::string Ticket::tickets_buying_time( std::string other)
{
    time_t _buying_time;
    struct tm* time_info;

    time(&_buying_time);
    time_info = localtime (& _buying_time);
    return other = asctime(time_info);
 }

 std::string Ticket::price()const
 {
     return  _data.at("price");
 }

 void Ticket::setPrice(const std::string &price)
 {
     _data.at("price") = price;
 }

 std::string Ticket::seat_class()const
 {
    return  _data.at("seat_class");
 }

 void Ticket::setSeat_class(const std::string &seat_class)
 {
    _data.at("seat_class") = seat_class;
 }

 std::string Ticket::departure_time()const
 {
     return  _data.at("departure_time");
 }

 void Ticket::setDeparture_time(const std::string &departure_time)
 {
    _data.at("departure_time") = departure_time;
 }

 std::string Ticket::arrival_time()const
 {
     return  _data.at("arrival_time");
 }

 void Ticket::setArrival_time(const std::string &arrival_time)
 {
     _data.at("arrival_time") = arrival_time;
 }

 std::string Ticket::customer_full_name()const
 {
     return  _data.at("customer_full_name");
 }

 void Ticket::setCustomer_full_name(const std::string &customer_full_name)
 {
     _data.at("customer_full_name") = customer_full_name;
 }

 std::string Ticket::buying_time()const
 {
     return _data.at("buying_time");
 }

 void Ticket::setBuying_time(const std::string &buying_time)
 {
    _data.at("buying_time") = buying_time;
 }

 std::string Ticket::destination() const
 {
     return _data.at("destination");
 }

 void Ticket::setDestination(const std::string &destination)
 {
     _data.at("destination") = destination;
 }


 void Ticket::print()
 {
     std::cout << _data.at("number") << " "<< _data.at("price") << std::endl;
 }

 std::map<std::string, std::string> Ticket::data() const
 {
     return _data;
 }

 void Ticket::setData(const std::map<std::string, std::string> &data)
 {
     _data = data;
 }

 std::string Ticket::load(std::string other)
 {
     std::string line;
     std::fstream in(other);
     if(in.is_open())
     {
         while (std::getline(in, line))
         {
             std::cout << line << std::endl;
         }
     }
     in.close();
     return other;
 }
