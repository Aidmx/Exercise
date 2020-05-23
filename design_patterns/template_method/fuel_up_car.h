

#pragma once
#include <string>
#include <iostream>

class IFuelUpCar
{
public:
    void StopCar()
    {
        std::cout<<"Stop Car"<<std::endl;
    }
    virtual void OpenFuelFiller() = 0;
    void FuelUp()
    {
        std::cout<<"FuelUp"<<std::endl; 
    }
}; 