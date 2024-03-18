#include <iostream>
#include "Canvas.h"

int main() {
    int width = 60, height = 60;
    Canvas c(width, height);
    //c.DrawRect(20,20,40,40, 'r');
    //c.FillRect(10,10,15,15, 'a');
    //c.DrawCircle(10,10,4,'c');
    c.Clear();
    c.DrawLine(1,1,50,50,'a');
    c.DrawRect(20,20,40,40, 'r');
    c.Print();
    return 0;
}
