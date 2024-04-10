#pragma once
#include "Car.h"

class Fiat : public Car{
public:
    Fiat();
    ~Fiat();

    float TimeToFinish(Wheather W, int l) override;
};