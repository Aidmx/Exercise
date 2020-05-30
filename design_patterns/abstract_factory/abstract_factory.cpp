

#include "abstract_factory.h"
#include "../factory_method/byd_factory.h"
#include "../factory_method/audi_factory.h"

IFactoryInterface *AbstractFactory::CreateFactory(FACTORY_TYPE type)
{
    switch (type)
    {
    case FACTORY_TYPE::AUDI: // 奥迪工厂
    {
        return new AudiFactory();
    }
    break;
    case FACTORY_TYPE::BYD: // 奥迪工厂
    {
        return new BYDFactory();
    }
    break;
    default:
        break;
    }
    return nullptr;
}