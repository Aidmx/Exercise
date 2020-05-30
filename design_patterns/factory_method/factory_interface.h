

#pragma once
#include "car.h"

class IFactoryInterface
{
public:
    virtual ICar *CreateCar() = 0;
};
