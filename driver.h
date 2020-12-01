#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>
#include <vector>

class Driver
{
public:
    Driver();
    Driver(std::string dbName);
   virtual ~Driver();
   virtual bool create_table(std::string tableName,const std::vector <std::string> &header) = 0;              
   virtual bool insert_raw(std::string tableName,const  std::vector <std::string> &data) = 0;
   virtual bool load_table(std::string tableName, std::vector <std::string> &data) = 0;
    protected:
    std::string _dbName;
};

#endif // DRIVER_H
