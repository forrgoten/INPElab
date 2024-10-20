#include <iostream>
#include <cmath>
using namespace std;
class Trigon
        {
        private:
            double l;
        public:
            void Set(double lenght)
            {
                l = lenght;
            }
            double Perimeter()
            {
                return l*3;
            }
            double Area()
            {
                return l*l * (sqrt(3)/4);
            }
        };
class Prism
        {
        private:
            double h;
            double l;
        public:
            void Set(double height, double lenght)
            {
                h = height;
                l = lenght;
            }
            double Volume()
            {
                return h * l*l * (sqrt(3)*4);
            }
            double Area()
            {
                return (l*l * (sqrt(3)/4)) * 2 + l * h * 3;
            }
            double Perimeter()
            {
                return l*6 + h*3;
            }
        };
int main() {
    int n, m;
    cin >> n >> m;
    Trigon *tri = new Trigon[n];
    Prism *pri = new Prism[m];
    double temp1, temp2;
    for(int i = 0; i < n;i++)
    {
        cout << "Enter l for trigon " << i << endl;
        cin >> temp1;
        tri[i].Set(temp1);
    }
    for(int i = 0;i < m;i++)
    {
        cout << "Enter l, h for prism " << i << endl;
        cin >> temp1 >> temp2;
        pri[i].Set(temp2,temp1);
    }
    double median=0;
    for(int i = 0;i < n;i++)
    {
        median += tri[i].Area();
    }
    median /= n;
    int curr = 0;
    for(int i = 0;i < n;i++)
    {
        if(tri[i].Area() < median)
            curr++;
    }
    double maxV = 0;
    int num = 0;
    for(int i = 0;i < m;i++)
    {
        if(pri[i].Volume() > maxV)
        {
            maxV = pri[i].Volume();
            num = i;
        }
    }
    cout << "Number of trigons with area less then median area is " << curr << endl;
    cout << "Prism with max volume has index " << num << " and volume " << maxV << endl;
    delete [] tri;
    delete [] pri;
    return 0;
}
