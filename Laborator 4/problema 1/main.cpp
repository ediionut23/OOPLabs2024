#include <iostream>
#include "Sort.h"

using namespace std;
int nr = 0;
int main() {
    Sort s1("1,8,3,4,9,8,7");
    s1.Print();
    cout << s1.GetElementsCount() << '\n';
    cout << s1.GetElementFromIndex(2) << '\n';
    //s.InsertSort(1);
    //s.BubbleSort(1);
    Sort s2(10,1,100);
    s1.QuickSort(1);
    s1.Print();
    s2.GetElementsCount() << '\n';
    s2.Print();
}
