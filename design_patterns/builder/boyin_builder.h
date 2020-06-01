
#pragma once
#include "airplane_builder.h"

class BoyinBuilder : public IAirPlaneBuilder
{
public:
    BoyinBuilder(/* args */) {}
    virtual ~BoyinBuilder() {}

    virtual void BuildEngine()
    {
        mAirplane.SetEngine("boyin 1280");
        Print(mAirplane.GetEngine());
    }
    virtual void BuildWings()
    {
        mAirplane.SetWings("boyin wings 36m");
        Print(mAirplane.GetWings());
    };
    virtual void BuildPropeller()
    {
        mAirplane.SetPropeller("boyin Propeller");
        Print(mAirplane.GetPropeller());
    };
    virtual void BuildCockpit()
    {
        mAirplane.SetCockpit("boyin Cockpit");
        Print(mAirplane.GetCockpit());
    }

private:
    void Print(std::string info)
    {
        std::cout<<"Bild "<<info <<std::endl;
    }
private:
    Airplane mAirplane;
};
