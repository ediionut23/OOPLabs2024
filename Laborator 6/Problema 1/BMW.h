#pragma once
#include "Car.h"

class BMW : public Car{
public:
    BMW();
    ~BMW();

    float TimeToFinish(Wheather W, int l) override;
};