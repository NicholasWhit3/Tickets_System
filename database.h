#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <vector>
#include "driver.h"
#include "txtdriver.h"
#include "htmldriver.h"

class Database
{
public:
    Database();
    void connect_database(const std::string dbAlias, const std::string  driver);             //dbAlias - database name
    void create_table(std::string tableName,const std::vector <std::string> &header);
    void insert_raw(std::string tableName,const std::vector <std::string> &data);
    //bool load_raw(std::string tableName);
    bool load_table(std::string tableName,std::vector <std::string> &data);

private:
   Driver* _driver;
   TxtDriver* _txtDriver;
   HtmlDriver* _htmlDriver;
   std::string _dbName;
};

#endif // DATABASE_H
