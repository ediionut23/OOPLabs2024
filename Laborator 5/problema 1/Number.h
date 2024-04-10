#pragma once
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Number
{
    // add data members
    char * s;
    int base;
public:
    int to10();
    char* xto10(int n, int base);

    Number(const char * value, int base); // where base is between 2 and 16
    ~Number();
    Number();

    // add operators and copy/move constructor

    Number(const Number &d);
    Number(const Number &&d);

    //operators
    char operator[](int index);
    friend Number operator+(Number nr1, Number nr2);
    friend Number operator-( Number nr1, Number nr2);
    Number& operator=(Number nr);
    Number& operator=(int nr);
    Number& operator=(char * c);
    bool operator>(Number nr);
    bool operator<(Number nr);
    Number& operator+=(Number nr);
    void operator--();
    void operator--(int numar);

    void SwitchBase(int newBase);
    void Print();
    char * Gets();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
};
