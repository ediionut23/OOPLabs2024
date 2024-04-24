#include <iostream>
using namespace std;

float operator "" _Kelvin(unsigned long long temp) {
    return (float)(temp - 273.15);
}

float operator "" _Fahrenheit(unsigned long long temp) {
    return (float)((temp - 32) * 5 / 9);
}

int main() {

    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    cout << a << " " << b;

    return 0;
}
