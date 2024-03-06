#include "Student.h"

void Student::setName(string  s) {
    Name = s;
}

string Student::getName() {
    return Name;
}

bool Student::setMathGrade(float x) {
    if(x  < 0 || x > 10)
        return false;
    MathGrade = x;
    return true;
}

float Student::getMathGrade() {
    return MathGrade;
}

bool Student::setEnglishGrade(float x) {
    if(x < 0 || x > 10)
        return false;
    EnglishGrade = x;
    return true;
}

float Student::getEnglishGrade() {
    return EnglishGrade;
}

bool Student::setHistoryGrade(float x) {
    if(x < 0 || x > 10)
        return false;
    HistoryGrade = x;
    return true;
}

float Student::getHistoryGrade() {
    return HistoryGrade;
}

float Student::avgGrade() {
    avg = (MathGrade + EnglishGrade + HistoryGrade)/3;
    return avg;
}
