

#pragma once

#include <string>
#include "car.h"

class AudiCar: public ICar
{
private:
    std::string name = "audi car";

public:
    AudiCar(/* args */) {}
    ~AudiCar() {}
    virtual std::string Name() override
    {
        return name;
    }
};
