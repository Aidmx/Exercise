#pragma once
#include "car.h"

class AudiCar : public ICar
{
private:
    std::string name = "audi";

public:
    AudiCar(/* args */) {}
    ~AudiCar() {}
    virtual std::string GetName() const override
    {
        return name;
    }
};
