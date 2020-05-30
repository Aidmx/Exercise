

#pragma once
#include "factory_interface.h"
#include "byd_car.h"

class BYDFactory : public IFactoryInterface
{
public:
    virtual ICar *CreateCar()
    {
        return new BydCar();
    }
};
