#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <iostream>

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a, double b) {
    return (int) (a + b);
}

int Math::Add(double a, double b, double c) {
    return (int) (a + b + c);
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

int Math::Mul(double a, double b) {
    return (int) (a * b);
}

int Math::Mul(double a, double b, double c) {
    return (int) (a * b * c);
}

int Math::Add(int count, ...) {
    va_list nums;
    int sum = 0;
    va_start(nums, count);
    for(int i = 0; i < count; i++){
        sum += va_arg(nums, int);
    }
    va_end(nums);
    return sum;
}

char *Math::Add(const char * a, const char * b) {
    if(a == nullptr || b == nullptr)
        return nullptr;

    int lungime1 = (int)strlen(a);
    int lungime2 = (int)strlen(b);
    int lungimeMax = (lungime1 > lungime2) ? lungime1 : lungime2;
    char * s = new char[lungimeMax + 2];

    int carry = 0;
    int i = lungime1 - 1;
    int j = lungime2 - 1;
    int index = 0;
    while(i >= 0 || j >= 0 || carry > 0){
        int cifra1 = (i >= 0) ? (a[i] - '0') : 0;
        int cifra2 = (j >= 0) ? (b[j] - '0') : 0;

        int suma = cifra1 + cifra2 + carry;
        carry = suma / 10;
        suma = suma % 10;

        s[index] =suma + '0';
        index++;

        i--;
        j--;
    }
    s[index] = '\0';
    i = 0;
    j = index - 1;

    while(i < j){
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }

    return s;
}
