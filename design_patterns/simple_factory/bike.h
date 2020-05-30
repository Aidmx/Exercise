#pragma once

#include <string>

class IBike
{
private:
    /* data */
public:
    virtual std::string GetName() const = 0;
};
