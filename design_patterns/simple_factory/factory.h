
#pragma once
#include "bike.h"

class Factory
{
private:
    /* data */
public:    
    enum BIKE_TYPE {
       BENZ,  // 奔驰汽车
       BMW,  // 宝马汽车
       AUDI  // 奥迪汽车
    };
    Factory() {}
    ~Factory() {}
    IBike* CreatBike(BIKE_TYPE type);
};