#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double  x, xn, xk, dx, a;
    a = 2.94;
    xn = 1.5;
    xk = 5.5;
    dx = 0.4;
    for(x = xn;x <= xk;x += dx)
        {
            cout << a*pow((a*pow(x,7))/(cos(a*a*a) + 1.31),1/5.0) << endl;

        }
    return 0;
}
