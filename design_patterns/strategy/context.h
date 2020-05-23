


#pragma once

#include <memory>
#include "strategy.h"


class Context
{
private:
    IStrategy* mStrategy;
public:
    Context(IStrategy* strategy)
    :mStrategy{strategy}
    {}

    void Travel()
    {
        if (mStrategy) {
            mStrategy->Travel();
        }
        
    }
};
