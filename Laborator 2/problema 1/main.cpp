#include "NumberList.h"

int main() {
    NumberList N;
    N.Init();
    N.Add(3);
    N.Add(2);
    N.Add(1);
    N.Add(4);
    N.Print();
    N.Sort();
    N.Print();

    return 0;
}
