

#pragma once

#include "airplane_builder.h"

class AirplaneDirector
{
public:
    AirplaneDirector(/* args */){}
    ~AirplaneDirector(){}
    public:
    void Create(IAirPlaneBuilder *builder) {
        if(builder == nullptr) return;
        builder->BuildEngine();
        builder->BuildPropeller();
        builder->BuildWings();
        builder->BuildCockpit();
    }
    void Print(IAirPlaneBuilder *builder)
    {
        if(builder == nullptr) return;
    }
};