

#pragma once
#include "factory_interface.h"
#include "audi_car.h"


class AudiFactory : public IFactoryInterface
{
public:
    AudiFactory(){}
    ~AudiFactory(){}
    virtual ICar* CreateCar() override 
    {
        return new AudiCar();
    }
};