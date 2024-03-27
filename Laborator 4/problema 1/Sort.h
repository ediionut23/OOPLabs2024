#pragma once
#include <string>

using namespace std;

class Sort
{
    // add data members
    int *v = nullptr;
    int cnt;

    int partition(int st, int dr);
    void quicksort(int st, int dr);
    void reverse();
public:
    // add constuctors:
    Sort(int NumberOfelem, int minVal, int maxVal);
    Sort();
    Sort(int a[], int size);
    Sort(int n, ...);
    Sort(string s);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount() const;
    int  GetElementFromIndex(int index);
};
