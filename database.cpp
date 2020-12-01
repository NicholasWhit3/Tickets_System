#include "database.h"
#include "driver.h"
#include <iostream>
#include <fstream>

Database::Database()
{
std::cout << "Working in Database..." << std::endl;
}

void Database::connect_database(const std::string dbAlias, const std::string driver)
{
    std::cout << "Working in connectDatabase..." << std::endl;
    if(driver == "text")
    {
        _txtDriver = new TxtDriver (dbAlias);
        _driver = _txtDriver;
    }else if (driver == "html")
    {
//        _htmlDriver = new HtmlDriver();
//        _driver  = _htmlDriver;
    }
    _dbName = dbAlias;

}

void Database::create_table(std::string tableName,const std::vector<std::string> &header)
{
    std::cout << "Working in Database::createTable..." << tableName  << " "<< header[0]<<std::endl;
    _driver->create_table(tableName, header);

}

void Database::insert_raw(std::string tableName, const std::vector<std::string> &data)
{
     std::cout << "Working in Database::insert_raw..." << std::endl;
     _driver->insert_raw(tableName, data);
}

bool Database::load_table(std::string tableName, std::vector<std::string> &data)
{
    std::cout << "Working in Database::load_table..." << std::endl;
    std::string str;
    std::ifstream fin;
    fin.open(_dbName + "_" + tableName);

    if(!fin.is_open())
    {
        std::cout << "Can't open table" << std::endl;
    }else{
        while(!fin.eof())       //end of file
        {
            std::getline(fin, str);
            if(!fin.eof())
            {
                data.push_back(str);
            }
        }
           fin.close();
           return  true;
    }
    return  false;
}

