#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int curr=1;
    double  x, xn, xk, dx, a, zmin, zmax;
    zmax=0;
    a = 2.94;
    xn = 1.5;
    xk = 5.5;
    dx = 0.4;
    zmin = a*pow((a*pow(xn,7))/(cos(a*a*a) + 1.31),1/5.0);
    for(x = xn;x <= xk;x += dx)
        {
        if(curr % 2 == 0)
            cout << a*pow((a*pow(x,7))/(cos(a*a*a) + 1.31),1/5.0) << endl;

        if(zmax < a*pow((a*pow(x,7))/(cos(a*a*a) + 1.31),1/5.0))
            zmax = a*pow((a*pow(x,7))/(cos(a*a*a) + 1.31),1/5.0);
        if(zmin > a*pow((a*pow(x,7))/(cos(a*a*a) + 1.31),1/5.0))
            zmin = a*pow((a*pow(x,7))/(cos(a*a*a) + 1.31),1/5.0);
            curr++;
        }
    cout << zmax - zmin;
    return 0;
}
