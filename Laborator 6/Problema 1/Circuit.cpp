#include "Circuit.h"
#include <iostream>
#include <algorithm>
#define FLT_MAX 99999
void Circuit::Setl(int lung) {
    this->l = l;
}

void Circuit::SetWheather(Wheather w) {
    wheather = w;
}

void Circuit::AddCar(Car *c) {
    v[nrcars++] = c;
}

void Circuit::Race() {
    std::sort(v, v + nrcars, [this](Car * A, Car *B){
        return (A->TimeToFinish(this->wheather, this->l) < B->TimeToFinish(this->wheather,this->l));
    });
}

void Circuit::ShowFinalRanks() {
    for(int i = 0; i < nrcars; i++)
        if(v[i]->TimeToFinish(this->wheather,this->l) != FLT_MAX){
            std::cout << "The" << i + 1 << "th place is " <<v[i]->name << '\n';
        }else break;
}

void Circuit::ShowWhoDidNotFinish() {
    for(int i = 0; i < nrcars; i++)
        if(v[i]->TimeToFinish(this->wheather, this->l) == FLT_MAX)
            std::cout << v[i]->name << " did not finish.\n";
}
