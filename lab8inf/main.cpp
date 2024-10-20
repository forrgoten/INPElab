#include <iostream>

using namespace std;

struct Complex
        {
        public:
            double real;
            double img;
        };
Complex operator+(const Complex &a, const Complex &b)
{
    Complex temp;
    temp.real=a.real+b.real;
    temp.img=a.img+b.img;
    return temp;
}

Complex operator*(const Complex &a, const Complex &b)
{
    Complex temp;
    temp.real = a.real*a.img - b.real*b.img;
    temp.img = a.real*a.img + b.real*b.img;
    return temp;
}
int main()
{
    double realp, imgp;
    cin >> realp >> imgp;
    Complex num1 = {realp, imgp};
    cin >> realp >> imgp;
    Complex num2 = {realp, imgp};
    Complex rez;
    rez = num1 + (num2*num2) + (num1+num2);
    cout << "Q = " << rez.real << "+" << rez.img << "i" << endl;
    return 0;
}
