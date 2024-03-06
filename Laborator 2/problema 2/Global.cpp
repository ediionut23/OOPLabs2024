#include "Global.h"
#include "Student.h"

int compareName(Student * s1, Student * s2){
    if(s1->getName() > s2->getName())
        return 1;
    else if(s1->getName() == s2->getName())
        return 0;
    else return -1;
}
int compareHistoryGrades(Student * s1, Student * s2){
    if(s1->getHistoryGrade() > s2->getHistoryGrade())
        return 1;
    else if(s1->getName() == s2->getName())
        return 0;
    else return -1;
}
int compareMathGrades(Student * s1, Student * s2){
    if(s1->getMathGrade() > s2->getMathGrade())
        return 1;
    else if(s1->getName() == s2->getName())
        return 0;
    else return -1;
}
int compareEnglishGrades(Student * s1, Student * s2){
    if(s1->getEnglishGrade() > s2->getEnglishGrade())
        return 1;
    else if(s1->getName() == s2->getName())
        return 0;
    else return -1;
}
int compareAvgGrades(Student * s1, Student * s2){
    if(s1->avgGrade() > s2->avgGrade())
        return 1;
    else if(s1->getName() == s2->getName())
        return 0;
    else return -1;
}
