
#ifndef AIRPLANE_H
#define AIRPLANE_H
#include <iostream>

class Airplane
{
public:
    Airplane(/* args */){}
    ~Airplane(){}

public:
    void SetEngine(std::string engine) { mEngine = engine; }
    void SetWings(std::string wings) { mWings = wings; }
    void SetPropeller(std::string propeller) { mPropeller = propeller; }
    void SetCockpit(std::string cockpit) { mCockpit = cockpit; }

    std::string GetEngine() { return mEngine; }
    std::string GetWings() { return mWings; }
    std::string GetPropeller() { return mPropeller; }
    std::string GetCockpit() { return mCockpit; }

private:
    std::string mEngine;    // 引擎
    std::string mWings;     // 机翼
    std::string mPropeller; // 螺旋桨
    std::string mCockpit;   // 驾驶舱
};
#endif
