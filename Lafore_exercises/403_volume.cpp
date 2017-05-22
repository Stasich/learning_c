// volume.cpp

#include <iostream>
using namespace std;

struct distance1
{
    int feet;
    float inches;
};
struct volume
{
    distance1 length, width, height;
};

int main()
{
    volume v1 = {{2,2},{4,5},{3,3}};
    float l,w,h;
    l = v1.length.feet + v1.length.inches/12;
    w = v1.width.feet + v1.width.inches/12;
    h = v1.height.feet + v1.height.inches/12;
    cout << "Объём помещения: " << l*w*h << " кубических футов. \n";
    return 0;
}