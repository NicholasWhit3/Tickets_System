#include "txtdriver.h"
#include "driver.h"
#include <fstream>
#include <iostream>

TxtDriver::TxtDriver()
{

}

TxtDriver::TxtDriver(std::string dbName)
{
    std::cout << "Working in TXTDriver..." << std::endl;
    _dbName = dbName;
    std::cout << "Database " << _dbName << " is ready" << std::endl;
}

TxtDriver::~TxtDriver()
{

}

bool TxtDriver::create_table(std::string tableName,const  std::vector<std::string> &header)
{
    std::cout << "Working in TxtDriver::createTable..." << std::endl;
    std::ofstream fout;
    fout.open(_dbName + "_" + tableName);
    if(!fout.is_open())
    {
        std::cout << "Can't creat table!" << std::endl;
    }else{
        for(auto value : header)
        {
            fout << value << "\t" << std::endl;
        }
        fout << "\n";
           fout.close();
           return  true;
    }
    return  false;
}

bool TxtDriver::insert_raw(std::string tableName, const std::vector<std::string> &data)
{
    std::cout << "Working in TxtDriver::insert_raw..." << std::endl;
    std::ofstream fout;
    fout.open(_dbName + "_" + tableName, std::ios::app);

    if(!fout.is_open())
    {
        std::cout << "Can't creat table!" << std::endl;
    }else{
        for(auto value : data)
        {
            fout << value << "\t" ;
        }
           fout << "\n";
           fout.close();
           return  true;
    }
    return  false;
}

bool TxtDriver::load_table(std::string tableName, std::vector<std::string> &data)
{
    std::cout << "Working in TxtDriver::load_table..." << std::endl;
    std::ifstream fin;
    fin.open(_dbName + "_" + tableName);

    if(!fin.is_open())
    {
        std::cout << "Can't creat table!" << std::endl;
    }else{
        for(std::string str ; std::getline(fin, str); data.push_back(str));
           fin.close();
           return  true;
    }
    return  false;
}
