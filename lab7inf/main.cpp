#include <iostream>
#include <array>

using namespace std;


array<double,4> gauss()
{
    double a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44, y1, y2, y3, y4;
    a11 = 5.7;
    a12 = -7.8;
    a13 = -5.6;
    a14 = -8.3;
    y1 = 2.7;
    a21 = 6.6;
    a22 = 13.1;
    a23 = -6.3;
    a24 = 4.3;
    y2 = -5.5;
    a31 = 14.7;
    a32 = -2.8;
    a33 = 5.6;
    a34 = -12.1;
    y3 = 8.6;
    a41 = 8.5;
    a42 = 12.7;
    a43 = -23.7;
    a44 = 5.7;
    y4 = 14.7;
    //1 row divided by 5.7
    a11 /= 5.7;
    a12 /= 5.7;
    a13 /= 5.7;
    a14 /= 5.7;
    y1 /= 5.7;
    //2 row minus 1 row multiplied by 6.6
    a21 = a21-a11*6.6;
    a22 = a22-a12*6.6;
    a23 = a23-a13*6.6;
    a24 = a24-a14*6.6;
    y2 = y2 - y1*6.6;
    //3 row minus 1 row multiplied by 14.7
    a31 = a31 - a11*14.7;
    a32 = a32 - a12*14.7;
    a33 = a33 - a13*14.7;
    a34 = a34 - a14*14.7;
    y3 = y3 - y1*14.7;
    //4 row minus 1 row multiplied by 8.5
    a41 = a41 - a11*8.5;
    a42 = a42 - a12*8.5;
    a43 = a43 - a13*8.5;
    a44 = a44 - a14*8.5;
    y4 = y4 - y1*8.5;
    //2 row divided by a22
    a21 /= a22;
    a23 /= a22;
    a24 /= a22;
    y2 /= a22;
    a22 /= a22;
    //1 row plus 2 row multiplied by abs(a12)
    a13 += a23 * abs(a12);
    a14 += a24 * abs(a12);
    y1 += y2 * abs(a12);
    a12 = 0;
    //3 row minus 2 row multiplied by a32
    a33 -= a23 * a32;
    a34 -= a24 * a32;
    y3 -= y2 * a32;
    a31 = 0;
    a32 = 0;
    //4 row minus 2 row multiplied by a42
    a43 -= a23 * a42;
    a44 -= a24 * a42;
    y4 -= y2 * a42;
    a41 = 0;
    a42 = 0;
    //3 row divided by a33
    a31 = 0;
    a32 = 0;
    a34 /= a33;
    y3 /= a33;
    a33 = 1;
    //1 row plus 3 row multiplied by abs(a13)
    a14 += a34 * abs(a13);
    y1 += y3 * abs(a13);
    a11 = 1;
    a12 = 0;
    a13 = 0;
    //2 row minus 3 row multiplied by a23
    a24 -= a34 * a23;
    y2 -= y3 * a23;
    a21 = 0;
    a22 = 1;
    a23 = 0;
    //4 row plus 3 row multiplied by abs(a43)
    a44 += a34 * abs(a43);
    y4 += y3 * abs(a43);
    a41 = 0;
    a42 = 0;
    a43 = 0;
    //4 row divided by a44
    y4 /= a44;
    a44 = 1;
    //1 row plus 4 row multiplied by abs(a14)
    y1 += y4 * abs(a14);
    a14 = 0;
    a13 = 0;
    a12 =0;
    a11 = 1;
    //2 row minus 4 row multiplied by a24
    y2 -= y4 * a24;
    a24 = 0;
    a23 = 0;
    a22 = 1;
    a21 = 0;
    //3 row plus 4 row multiplied by abs(a34)
    y3 += y4 * abs(a34);
    a34 = 0;
    a33 = 1;
    a32 = 0;
    a31 = 0;
    array<double,4> g_array = {y1,y2,y3,y4};
    return g_array;
}

int main()
{
    array<double,4> x = {1,1,2,-3};
    array<double,4> y = gauss();
    double scalar = x[0]*y[0] + x[1]*y[1] + x[2]*y[2] + x[3]*y[3];
    cout << scalar;
}