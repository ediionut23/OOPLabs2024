#include "Fiat.h"
#define FLT_MAX 99999

Fiat::Fiat() :Car() {
    fuelCapacity = 250;
    fuelConsumption = 4;
    averageSpeed[0] = 105;
    averageSpeed[1] = 102;
    averageSpeed[2] = 115;

    const char * c = "Fiat";
    int n = 0;
    for(int i = 0; c[i]; i++)
        n++;
    name = new char[n+1];
    name = (char *)c;
}

Fiat::~Fiat() {
    delete[] name;
}

float Fiat::TimeToFinish(Wheather W, int l) {
    float Km = (float) fuelCapacity/ (float) fuelConsumption;
    if(Km < float(l))
        return FLT_MAX;
    float time = (float) l/(float)averageSpeed[W];
    return time;
}
