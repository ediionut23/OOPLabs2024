#include "BMW.h"
#define FLT_MAX 99999

BMW::BMW() :Car() {
    fuelCapacity = 240;
    fuelConsumption = 3;
    averageSpeed[0] = 140;
    averageSpeed[1] = 140;
    averageSpeed[2] = 150;

    const char * c = "BMW";
    int n = 0;
    for(int i = 0; c[i]; i++)
        n++;
    name = new char[n+1];
    name = (char *)c;
}

BMW::~BMW() {
    delete[] name;
}

float BMW::TimeToFinish(Wheather W, int l) {
    float Km = (float) fuelCapacity/ (float) fuelConsumption;
    if(Km < float(l))
        return FLT_MAX;
    float time = (float) l/(float)averageSpeed[W];
    return time;
}