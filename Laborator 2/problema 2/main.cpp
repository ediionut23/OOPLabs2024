#include <iostream>
#include <string>
#include "Student.h"
#include "Global.h"

using namespace std;

int main() {
    string s;
    Student Gigel, Andrei;
    Gigel.setName("Gigel");
    Andrei.setName("Andrei");
    printf("Numele lui este: %s \n", Gigel.getName().c_str());
    printf("Numele lui este: %s \n", Andrei.getName().c_str());
    Gigel.setMathGrade(2.6);
    Gigel.setHistoryGrade(6.7);
    Gigel.setEnglishGrade(2.2);
    Andrei.setMathGrade(3);
    Andrei.setHistoryGrade(6.7);
    Andrei.setEnglishGrade(1.2);
    printf("Media notelor este: %2.2f \n ", Gigel.avgGrade());
    cout << compareName(&Andrei, &Gigel) << endl;
    cout << compareMathGrades(&Andrei, &Gigel) << endl;
    cout << compareEnglishGrades(&Andrei,&Gigel) << endl;
    cout << compareHistoryGrades(&Andrei, &Gigel) << endl;
    cout << compareAvgGrades(&Andrei, &Gigel);
    return 0;
}
