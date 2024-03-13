#include <iostream>
#include "Math.h"
using namespace std;

int main() {
    char a[] = "23";
    char b[] = "5";
    char * res = Math::Add(a, b);
    cout << res << endl;
    cout << Math::Add(1,2) << endl;
    cout << Math::Add(1.5,2.2) << endl;
    cout << Math::Add(5,1,2,3,4,5) << endl;
    cout << Math::Add(1, 2 ,3) << endl;
    cout << Math::Add(1.5,2.5,3.5) << endl;
    cout << Math::Mul(1, 2) << endl;
    cout << Math::Mul(1.2,1.3) << endl;
    cout << Math::Mul(1.2,2.2,3.3) << endl;
    cout << Math::Mul(1, 2, 3);

    return 0;
}
