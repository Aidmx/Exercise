
#include "factory.h"
#include "audi_bike.h"

IBike* Factory::CreatBike(Factory::BIKE_TYPE type)
{
    IBike *pBike = nullptr;
    switch (type)
    {
    case AUDI:
        pBike = new AudiBike(); // 奥迪汽车
        break;
    default:
        break;
    }
    return pBike;
}