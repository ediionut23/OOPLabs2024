#pragma once
#include <string>

using namespace std;

class Student{
    string Name;
    float MathGrade, EnglishGrade, HistoryGrade;
    float avg;

public:
    void setName(string s);
    string getName();
    bool setMathGrade(float x);
    float getMathGrade();
    bool setEnglishGrade(float x);
    float getEnglishGrade();
    bool setHistoryGrade(float x);
    float getHistoryGrade();
    float avgGrade();
};