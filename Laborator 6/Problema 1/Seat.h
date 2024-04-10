#pragma once
#include "Car.h"

class Seat : public Car{
public:
    Seat();
    ~Seat();

    float TimeToFinish(Wheather W, int l) override;
};