
#include "factory.h"
#include "audi_car.h"

ICar* Factory::CreateCar(Factory::CAR_TYPE type)
{
    ICar *pCar = nullptr;
    switch (type)
    {
    case AUDI_CAR:
        pCar = new AudiCar(); // 奥迪汽车
        break;
    default:
        break;
    }
    return pCar;
}