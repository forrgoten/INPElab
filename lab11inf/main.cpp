#include<iostream>
#include <cmath>

using namespace std;

class LINE
{
private:
    double k, b;
public:
    void Set(double kn, double bn)
    {
        k = kn;
        b = bn;
    }
    void Print()
    {
        if (b > 0.0)
            cout << k << "x+" << b << endl;
        else
            cout << k << "x" << b << endl;
    }
    void Intersection()
    {
        double y = b;
        double x = -k / b;
        cout << "y = " << y << endl << "x = " << x << endl;
    }
    LINE()
    {
        k = 0.0;
        b = 0.0;
    }
    ~LINE()
    {
        cout << "terminate" << endl;
    }
    bool operator!=(const LINE& line2)
    {
        return -1 == (this->k * line2.k);
    }
    double operator%(const LINE& line2)
    {
        if(atan(this->k) > line2.k)
        {
            return atan(this->k) - atan(line2.k);
        }
        if(atan(line2.k) > atan(this->k))
        {
            return atan(line2.k) - atan(this->k);
        }
    }
};

int main()
{
    double k,b;
    cout << "line1:" << endl;
    cin >> k >> b;
    LINE line1;
    line1.Set(k,b);
    cout << "line2:" << endl;
    cin >> k >> b;
    LINE line2;
    line2.Set(k, b);
    line1.Intersection();
    line2.Intersection();
    if(line1 != line2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    cout << line1%line2 << endl;
    return 0;
}