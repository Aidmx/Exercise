#pragma once
#include "bike.h"

class AudiBike : public IBike
{
private:
    std::string name = "audi";

public:
    AudiBike(/* args */) {}
    ~AudiBike() {}
    virtual std::string GetName() const override
    {
        return name;
    }
};
