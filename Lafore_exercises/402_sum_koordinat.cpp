// 402_sum_koordinat.cpp
#include <iostream>
using namespace std;

struct point
{
    int x,y;
};

int main()
{
    point point1, point2, pointSum;
    cout << "Введите координаты точки p1: ";
    cin >> point1.x >> point1.y;
    cout << "Введите координаты точки p2: ";
    cin >> point2.x >> point2.y;
    pointSum.x = point1.x + point2.x;
    pointSum.y = point1.y + point2.y;
    cout << "Координаты точки p1+p2: " << pointSum.x << " " << pointSum.y << endl;
    return 0;
}