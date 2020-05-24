
#pragma once
#include "car.h"

class Factory
{
private:
    /* data */
public:    
    enum CAR_TYPE {
       BENZ_CAR,  // 奔驰汽车
       BMW_CAR,  // 宝马汽车
       AUDI_CAR  // 奥迪汽车
    };
    Factory() {}
    ~Factory() {}
    ICar* CreateCar(CAR_TYPE type);
};