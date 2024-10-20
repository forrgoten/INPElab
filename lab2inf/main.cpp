#include <iostream>
#include <cmath>

using namespace std;

double x1, x2, x3, method;

void solve(double a,double b,double c,double d)
{
    b /= a;
    c /= a;
    d /= a;
    double disc, q, r, dum1, s, t, term1, r13;
    q = (3.0*c - (b*b))/9.0;
    r = -(27.0*d) + b*(9.0*c - 2.0*(b*b));
    r /= 54.0;
    disc = q*q*q + r*r;
    term1 = (b/3.0);
    double x1_real, x2_real, x3_real;
    if (disc > 0)
    {
        s = r + sqrt(disc);
        s = s<0 ? -cbrt(-s) : cbrt(s);
        t = r - sqrt(disc);
        t = t<0 ? -cbrt(-t) : cbrt(t);
        x1_real = -term1 + s + t;
        term1 += (s + t)/2.0;
        x3_real = x2_real = -term1;
        x1 = x1_real;
        x2 = x2_real;
        x3 = x3_real;
        method = 1;
    }
    else if (disc == 0)
    {
        r13 = r<0 ? -cbrt(-r) : cbrt(r);
        x1_real = -term1 + 2.0*r13;
        x3_real = x2_real = -(r13 + term1);
        x1 = x1_real;
        x2 = x2_real;
        x3 = x3_real;
        method = 2;
    }
    else
    {
        q = -q;
        dum1 = q*q*q;
        dum1 = acos(r/sqrt(dum1));
        r13 = 2.0*sqrt(q);
        x1_real = -term1 + r13*cos(dum1/3.0);
        x2_real = -term1 + r13*cos((dum1 + 2.0*M_PI)/3.0);
        x3_real = -term1 + r13*cos((dum1 + 4.0*M_PI)/3.0);
        x1 = x1_real;
        x2 = x2_real;
        x3 = x3_real;
        method = 3;
    }
}

int main()
{
    double a,b,c,d,f,g,C,D,y1,y2,y3;
    a=b=c=d=f=g=C=D=y1=y2=y3=0;
    cin>>a>>b>>c>>d>>f>>g;
    //ax^3 + bx^2 + (c-f)x - (d-g)
    C = c - f;
    D = d - g;
    solve(a,b,C,D);
    y1 = f*x1 + g;
    y2 = f*x2 + g;
    y3 = f*x3 + g;
    cout << "intersection points:" << endl;
    if(method == 1)
    {
        cout << "x1: " << x1 << endl << "y1: " << y1 << endl;
        cout << "x2: " << x2 << endl << "y2: " << y2 << endl;
        cout << "intersection points 2 and 3 matches" << endl;
    }
    if(method == 2)
    {
        cout << "x1: " << x1 << endl << "y1: " << y1 << endl;
        cout << "x2: " << x2 << endl << "y2: " << y2 << endl;
        cout << "intersection points 2 and 3 matches" << endl;
    }
    if(method == 3)
    {
        cout << "x1: " << x1 << endl << "y1: " << y1 << endl;
        cout << "x2: " << x2 << endl << "y2: " << y2 << endl;
        cout << "x3: " << x3 << endl << "y3: " << y3 << endl;
    }
    return 0;
}
