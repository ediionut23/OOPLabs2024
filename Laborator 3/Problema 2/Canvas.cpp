#include "Canvas.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;



int euclidianDistance(int a, int b, int x, int y){
    return (int) sqrt((a-x) * (a-x) + (b-y) * (b-y));
}

Canvas::Canvas(int width, int height) {
    n = width;
    m = height;
    c = new char *[n] ;
    for(int i = 0; i < n; i++)
        c[i] = new char[m];

}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(euclidianDistance(x,y,i,j) == ray)
                c[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(euclidianDistance(x,y,i,j) <= ray)
                c[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for(int j = left; j <= right; j++)
        c[top][j] = c[bottom][j] = ch;
    for(int i = top; i <= right; i++)
        c[i][left] = c[i][right] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for(int i = top; i <= bottom; i++)
        for(int j = left; j <= right; j++)
            c[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch) {
    c[x][y] = ch;
}

void Canvas::Print() {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            std::cout << c[i][j];
        std::cout << '\n';
    }
}
void Canvas::Clear() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            c[i][j] = ' ';
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    double panta = ((double) (y2- y1)) / ((double) (x2 - x1));
    double u = (double) y2- (double)(panta * (double) x2);
    for(int x = x1; x <= x2; x++){
        int y = (int) round(panta * (double) x + u);
        SetPoint(x,y,ch);
    }
}
