

#pragma once

#include <string>
#include "car.h"

class BydCar: public ICar
{
private:
    std::string name = "byd car";

public:
    BydCar(/* args */) {}
    ~BydCar() {}
    virtual std::string Name() override
    {
        return name;
    }
};
