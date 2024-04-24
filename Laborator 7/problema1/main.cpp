#include <iostream>
using namespace std;

float operator "" _Kelvin(long double temp) {
    return (float)(temp - 273.15);
}

float operator "" _Fahrenheit(long double temp) {
    return (float)((temp - 32) * 5 / 9);
}

int main() {

    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;

    cout << a << " " << b;

    return 0;
}
