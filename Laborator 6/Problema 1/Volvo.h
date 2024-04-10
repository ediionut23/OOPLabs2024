#pragma once
#include "Car.h"

class Volvo : public Car{
public:
    Volvo();
    ~Volvo();

    float TimeToFinish(Wheather W, int l) override;
};