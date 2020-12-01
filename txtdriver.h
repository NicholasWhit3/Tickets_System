#ifndef TXTDRIVER_H
#define TXTDRIVER_H
#include "driver.h"

class TxtDriver : public Driver
{
public:
    TxtDriver();
    TxtDriver(std::string dbName);
    ~TxtDriver();
    bool create_table(std::string tableName, const std::vector <std::string> &header) override;
    bool insert_raw(std::string tableName,  const std::vector <std::string> &data) override;
    bool load_table(std::string tableName, std::vector <std::string> &data) override;
};

#endif // TXTDRIVER_H
