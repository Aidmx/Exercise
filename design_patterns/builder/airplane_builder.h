

#ifndef BUILDER_H
#define BUILDER_H
#include "airplane.h"

class IAirPlaneBuilder
{
public:
    IAirPlaneBuilder(/* args */){}
    virtual ~IAirPlaneBuilder(){} 

    virtual void BuildEngine() = 0;
    virtual void BuildWings() = 0;
    virtual void BuildPropeller() = 0;
    virtual void BuildCockpit() = 0;
};
#endif