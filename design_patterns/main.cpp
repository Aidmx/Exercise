

#pragma once
#include "strategy/context.h"
#include "strategy/strategy.h"
#include "strategy/car_strategy.h"
#include "template_method/fuel_up_car.h"
#include "template_method/fuel_up_audi_car.h"
#include "simple_factory/factory.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

int main(int argc, char* argv[])
{
    /* 
        strategy 策略模式
    */
    IStrategy* strategy = (new CarStrategy()); 
    Context context(strategy);
    context.Travel();
    SAFE_DELETE(strategy);

    /* 
        template Method 模板方法
    */
    IFuelUpCar* fuelup = new FuelUpAudiCar();
    fuelup->StopCar();
    fuelup->OpenFuelFiller();
    fuelup->FuelUp();
    
    SAFE_DELETE(fuelup);

    /* 
        simple factory 简单工厂
    */
    Factory simple_factory;
    ICar *car = simple_factory.CreateCar(Factory::CAR_TYPE::AUDI_CAR);
    if (car != nullptr)
    {
        cout<<"Create car name is "<<car->GetName()<<endl;
    }
    SAFE_DELETE(car);
    system("pause");
    return 0;
}
