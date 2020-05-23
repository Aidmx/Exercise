
#pragma once
#include <iostream>
#include "strategy.h"

class CarStrategy: public IStrategy
{    
private:
    /* data */
public:
    CarStrategy(/* args */){}
    ~CarStrategy(){}
public:
    virtual void Travel() override
    {
        std::cout<<"travel by car"<<std::endl;
    }

};
