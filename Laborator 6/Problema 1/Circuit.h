#pragma once
#define Max_cars 100

#include "Car.h"
#include "Wheather.h"

class Circuit{
    int l = 0;
    int nrcars = 0;
    Wheather wheather = Sunny;
public:
    Car *v[Max_cars] = {nullptr};

    void SetWheather(Wheather w);
    void Setl(int lung);
    void AddCar(Car * c);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};