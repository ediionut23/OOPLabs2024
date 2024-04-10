#pragma once
#include "Wheather.h"

class Car{
public:
    char* name = nullptr;
    int fuelCapacity = 0;
    int fuelConsumption = 0;
    int averageSpeed[3] = {0};

    virtual float TimeToFinish(Wheather W, int l) = 0;

    Car() = default;
};