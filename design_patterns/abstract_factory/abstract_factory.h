

#pragma once
#include "../factory_method/factory_interface.h"


class AbstractFactory
{
public:
    enum FACTORY_TYPE {
        AUDI,  // 奥迪工厂
        BYD  // 奥迪工厂
    };

    AbstractFactory(/* args */){}
    ~AbstractFactory(){}

    IFactoryInterface* CreateFactory(FACTORY_TYPE type);
}; 
