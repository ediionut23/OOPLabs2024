#pragma once
#include "Car.h"

class RangeRover : public Car{
public:
    RangeRover();
    ~RangeRover();

    float TimeToFinish(Wheather W, int l) override;
};