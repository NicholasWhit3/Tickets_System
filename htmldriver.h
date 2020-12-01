#ifndef HTMLDRIVER_H
#define HTMLDRIVER_H
#include "driver.h"

class HtmlDriver : public Driver
{
public:
    HtmlDriver();
    bool create_table(std::string tableName, const std::vector <std::string> &header) override;

private:
};

#endif // HTMLDRIVER_H
