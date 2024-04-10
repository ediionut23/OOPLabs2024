#include "Seat.h"
#define FLT_MAX 99999

Seat::Seat() :Car() {
    fuelCapacity = 340;
    fuelConsumption = 4;
    averageSpeed[0] = 110;
    averageSpeed[1] = 110;
    averageSpeed[2] = 120;

    const char * c = "Seat";
    int n = 0;
    for(int i = 0; c[i]; i++)
        n++;
    name = new char[n+1];
    name = (char *)c;
}

Seat::~Seat() {
    delete[] name;
}

float Seat::TimeToFinish(Wheather W, int l) {
    float Km = (float) fuelCapacity/ (float) fuelConsumption;
    if(Km < float(l))
        return FLT_MAX;
    float time = (float) l/(float)averageSpeed[W];
    return time;
}