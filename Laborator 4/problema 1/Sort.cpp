#include "Sort.h"
#include <random>
#include <cstdarg>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Sort::Sort(int NumberOfelem, int minVal, int maxVal) {
    random_device random;
    uniform_int_distribution<int> intDistribution(minVal, maxVal);
    delete[] v;
    v = new int[NumberOfelem];
    cnt = NumberOfelem;
    for (int i = 0; i < NumberOfelem; i++)
        v[i] = intDistribution(random);
}

Sort::Sort() : v(new int[6]{6,5,4,3,2,1}) , cnt(6){}

Sort::Sort(int a[], int size){
    delete[] v;
    v = new int[size];
    cnt = size;
    for(int i = 0; i < size; i++)
        v[i] = a[i];
}

Sort::Sort(int n, ...) {
    va_list List;
    va_start(List, n);
    cnt = n;
    delete[] v;
    v = new int[cnt];
    for(int i = 0; i < n; i++)
        v[i] = va_arg(List, int);
    va_end(List);
}

Sort::Sort(std::string s) {
    char aux;
    int size = 0;
    int p;
    for(int i = 0; s[i]; i++)
        if(s[i] == ',')
            size++;
    cnt = size + 1;
    v = new int[cnt];
    size = 0;
    int n = 0;
    for(int i = 0; s[i]; i++){
        if(s[i] == ',')
        {
            p = 1;
            n = 0;
            for(int j = i-1; j >= 0 && s[j] != ','; j--){
                int cif = s[j] - '0';
                n = n  + cif * p;
                p = p * 10;
            }
            v[size] = n;
            size++;
        }
    }
    int cn = s.size() - 1;
    p = 1;
    for(int i = cn; s[i] != ','; i--){
        n = 0;
        int cif = s[i] - '0';
        n = n + cif * p;
        p =p * 10;
    }
    v[size] = n;
}




void Sort::InsertSort(bool ascendent) {
    int i, key, j;
    for(i = 0; i < cnt; i++){
        key = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > key){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
    if(!ascendent)
        reverse();
}

void Sort::BubbleSort(bool ascendent) {
    int i,j;
    bool swapped;
    for(i = 0; i < cnt - 1; i++){
        swapped = false;
        for(j = 0; j < cnt - i - 1; j++){
            if(v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
    if(!ascendent)
        reverse();
}



int Sort::partition(int st, int dr) {
    int pozDr = dr;
    int pi = (st + dr) /2;
    swap(v[pi], v[dr]);
    pi = v[dr];
    dr--;
    while(st <= dr){
        while(v[st] <= pi && st <= dr)
            st++;
        while(v[dr] >= pi && st <= dr)
            dr--;
        if(st <= dr){
            swap(v[st], v[dr]);
            st++;
            dr--;
        }
    }
    swap(v[st], v[pozDr]);
    return st;
}


void Sort::quicksort(int st, int dr) {
    if(st < dr){
        int pivot = partition(st, dr);
        quicksort(st, pivot - 1);
        quicksort(pivot + 1, dr);
    }
}

void Sort::QuickSort(bool ascendent) {
    quicksort(0, GetElementsCount()-1);
    if(!ascendent)
        reverse();
}

void Sort::Print() {
    for(int i = 0; i < cnt; i++)
        cout << v[i] << " ";
    cout << endl;
}

int Sort::GetElementsCount() const {
    return cnt;
}

int Sort::GetElementFromIndex(int index) {
    if(index < 0 || index >= cnt)
        return 0;
    return v[index];
}

void Sort::reverse() {
    for(int i = 0; i < cnt/2; i++)
        swap(v[i], v[cnt - i - 1]);
}