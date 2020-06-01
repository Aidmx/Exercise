

#pragma once
#include "strategy/context.h"
#include "strategy/strategy.h"
#include "strategy/car_strategy.h"
#include "template_method/fuel_up_car.h"
#include "template_method/fuel_up_audi_car.h"
#include "simple_factory/factory.h"
#include "factory_method/audi_factory.h"
#include "abstract_factory/abstract_factory.h"
#include "builder/airplane_director.h"
#include "builder/boyin_builder.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)  \
    {                   \
        if (p)          \
        {               \
            delete (p); \
            (p) = NULL; \
        }               \
    }
#endif

using namespace std;

int main(int argc, char *argv[])
{
    /* 
        strategy 策略模式
    */
    IStrategy *strategy = (new CarStrategy());
    Context context(strategy);
    context.Travel();
    SAFE_DELETE(strategy);

    /* 
        template Method 模板方法
    */
    IFuelUpCar *fuelup = new FuelUpAudiCar();
    fuelup->StopCar();
    fuelup->OpenFuelFiller();
    fuelup->FuelUp();

    SAFE_DELETE(fuelup);

    /* 
        simple factory 简单工厂
    */
    Factory simple_factory;
    IBike *bike = simple_factory.CreatBike(Factory::BIKE_TYPE::AUDI);
    if (bike != nullptr)
    {
        cout << "Create bike name is " << bike->GetName() << endl;
    }
    SAFE_DELETE(bike);
    /* abstract factory 抽象工厂 */
    AbstractFactory factoryCreator;
    IFactoryInterface* bydFactory = factoryCreator.CreateFactory(AbstractFactory::FACTORY_TYPE::BYD);
    if (bydFactory != nullptr)
    {
        auto car = bydFactory->CreateCar();
        if (car != nullptr)
        {
            cout << "Create bike name is " << car->Name() << endl;
        }
        SAFE_DELETE(car);
    }
    SAFE_DELETE(bydFactory);
    

    /* factory method  工厂方法*/
    IFactoryInterface* factory = new AudiFactory();
    if (factory != nullptr)
    {
        ICar *car = factory->CreateCar();
        if (car != nullptr)
        {
            cout << "Create bike name is " << car->Name() << endl;
        }
        SAFE_DELETE(car);
    }
    SAFE_DELETE(factory);

    /* builder */
    IAirPlaneBuilder *builder = new BoyinBuilder();
    if (builder != nullptr)
    {
        AirplaneDirector director;
        director.Create(builder);
    }
    SAFE_DELETE(builder);

    system("pause");
    return 0;
}
