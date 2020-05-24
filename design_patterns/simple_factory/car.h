#pragma once

#include <string>

class ICar
{
private:
    /* data */
public:
    virtual std::string GetName() const = 0;
};
