#include "Volvo.h"
#define FLT_MAX 99999

Volvo::Volvo() :Car() {
    fuelCapacity = 340;
    fuelConsumption = 1;
    averageSpeed[0] = 100;
    averageSpeed[1] = 100;
    averageSpeed[2] = 130;

    const char * c = "Volvo";
    int n = 0;
    for(int i = 0; c[i]; i++)
        n++;
    name = new char[n+1];
    name = (char *)c;
}

Volvo::~Volvo() {
    delete[] name;
}

float Volvo::TimeToFinish(Wheather W, int l) {
    float Km = (float) fuelCapacity/ (float) fuelConsumption;
    if(Km < float(l))
        return FLT_MAX;
    float time = (float) l/(float)averageSpeed[W];
    return time;
}
