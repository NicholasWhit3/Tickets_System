#include "airport.h"
#include "ticket.h"
#include <ctime>
#include "database.h"
#include <sstream>
std::string gen_flight_number()
{
    int number = rand() % 700+300;
    return std::to_string(number);
}
std::string gen_departure_time()
{
    int hour, min;
    std::string dep_time;
    hour = rand() % 24;
    min = rand() % 60;
    dep_time = std::to_string(hour) + ":" + std::to_string(min);
    return dep_time;
}
void gen_seat_class(int &a, int &b, int &c, int& value)
{
    value = rand() % 50 + 150;
    a = value * 0.2;
    b = value * 0.3;
    c = value * 0.5;
}
std::vector <int> split(const std::string &str, char spacer)
{
   std::string split_str;
   std::vector <int> data;
   std::stringstream stream(str);
   while(std::getline(stream, split_str, spacer))
   {
      data.push_back(std::stoi(split_str));
   }
   return data;
}
std::string gen_arrival_time(std::string departure_time)
{

    int hour, min;
    std::stringstream stream(departure_time);
    std::string sHours;
    std::getline(stream, sHours, ':');
    std::string sMin;
    std::getline(stream, sMin, ':');
    hour = (std::stoi(sHours) + rand() % 10) % 24;
    min = (std::stoi(sMin) + rand() % 60) % 60;
    return std::to_string(hour) + ":" + std::to_string(min);

 }

std::string gen_price(int seat_class, std::string arrival_time, std::string departure_time)
{

   auto a_time = split(arrival_time, ':');
   auto d_time = split(departure_time, ':');
   int hours = a_time[0] - d_time[0];
   int min = a_time[1] - d_time[1];
   double time = (double)((min / 60 * 100) + hours);
   double coef = (double)(seat_class / 2.0) * time;
   double price = coef * 40 + 20;
   return std::to_string(price);

}


Airport::Airport(Database& dataBase) :_dataBase(dataBase),  _ticket_base(*new TicketBase(_dataBase)), _ticket_window(*new Ticket_Window(_ticket_base))
{
    srand(time(nullptr));
    std::cout << "Working in Airport..." << std::endl;

    _dataBase.connect_database("airport", "text");
    _ticket_base.create_ticket(get_tickets_from_company());

}

Airport::~Airport()
{
    delete &_ticket_base;
    delete &_ticket_window;
}

std::vector <std::vector <std::string>> Airport::get_tickets_from_company()
{
    std::vector <std::vector <std::string>> tickets;
    std::string flight_number;
    std::string destination;
    std::string departure_time;
    std::string arrival_time;
    std::string price;
    const int seat_class_a = 50;
    const int seat_class_b = 60;
    const int seat_class_c = 70;



    flight_number = gen_flight_number();
    destination = gen_destination();
    departure_time = gen_departure_time();
    arrival_time = gen_arrival_time(departure_time);
    price = gen_price(3, arrival_time, departure_time);

    std::vector <std::string> ticket;
    ticket.push_back(flight_number);
    ticket.push_back(destination);
    ticket.push_back(departure_time);
    ticket.push_back(arrival_time);
    ticket.push_back(price);
    ticket.push_back(std::to_string(seat_class_a));
    tickets.push_back(ticket);
    ticket.clear();
    price = gen_price(2, arrival_time, departure_time);
    ticket.push_back(flight_number);
    ticket.push_back(destination);
    ticket.push_back(departure_time);
    ticket.push_back(arrival_time);
    ticket.push_back(price);
    ticket.push_back(std::to_string(seat_class_b));
    tickets.push_back(ticket);
    ticket.clear();
    price = gen_price(1, arrival_time, departure_time);
    ticket.push_back(flight_number);
    ticket.push_back(destination);
    ticket.push_back(departure_time);
    ticket.push_back(arrival_time);
    ticket.push_back(price);
    ticket.push_back(std::to_string(seat_class_c));
    tickets.push_back(ticket);

    for(auto tick : tickets)
    {
        for(auto str1 : tick)
        {
                std::cout << str1 << " ";
        }
                std::cout << "\n";
    }
    return tickets;
}

std::string Airport::airport_name() const
{
    return _airport_name;
}

void Airport::setAirport_name(const std::string &airport_name)
{
    _airport_name = airport_name;
}

std::string Airport::airport_location() const
{
    return _airport_location;
}

void Airport::setAirport_location(const std::string &airport_location)
{
    _airport_location = airport_location;
}

float Airport::temperature_outside() const
{
    return _temperature_outside;
}

void Airport::setTemperature_outside(float temperature_outside)
{
    _temperature_outside = temperature_outside;
}

bool Airport::parking_place() const
{
    return _parking_place;
}

void Airport::setParking_place(bool parking_place)
{
    _parking_place = parking_place;
}

bool Airport::taxi() const
{
    return _taxi;
}

void Airport::set_Taxi(bool taxi)
{
    _taxi = taxi;
}

std::string Airport::gen_destination()
{
    srand((unsigned) time(0));
    std::vector <std::string> destination;
     _dataBase.load_table("Destination.txt", destination);
     if(sizeof (destination) == 0)
     {
         std::cout << "Can't generate the destination!" << std::endl;
     }else{
         int i = rand() % sizeof(destination);
         return destination[i];
     }
      // размер вектора, случайное число % размер. от 0 до размера вектора. Вернуть случайное число из вектора.
}


