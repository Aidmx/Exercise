
#pragma once
#include <string>
#include "fuel_up_car.h"

class FuelUpAudiCar :public IFuelUpCar
{
private:
    std::string mName = "audi";
public:
    FuelUpAudiCar(){}
    virtual ~FuelUpAudiCar(){}

    virtual void OpenFuelFiller() override
    {
        std::cout<<"Open fuel filler of "<<GetName()<<std::endl; 
    }
private:
    virtual std::string GetName()
    {
        return mName;
    }
};
