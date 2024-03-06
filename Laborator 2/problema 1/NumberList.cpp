#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::Init() {
    count = 0;
}

bool NumberList::Add(int x) {
    if(x >= 10)
        return false;
    numbers[count++] = x;
    return true;
}

void NumberList::Sort() {
    for(int i = 0; i < count - 1; i++)
        for(int j = i + 1; j <= count - 1; j++)
            if(numbers[i] > numbers[j])
                swap(numbers[i], numbers[j]);
}

void NumberList::Print() {
    printf( "%s\n", "Vectorul este:");
    for(int i = 0 ; i < count; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}
