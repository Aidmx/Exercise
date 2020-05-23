

#pragma once
#include "strategy/context.h"
#include "strategy/strategy.h"
#include "strategy/car_strategy.h"


#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main(int argc, char* argv[])
{
    IStrategy* strategy = (new CarStrategy()); 
    Context context(strategy);
    context.Travel();

    return 0;
}
