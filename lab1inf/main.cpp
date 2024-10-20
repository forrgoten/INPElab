#include <cmath>
#include <iostream>

using namespace std;


int main()
{
	float alf, beta;
    cout << "Input1\n";
    cin >> alf;
    cout << "Input2\n";
    cin >> beta;
	float y = pow(cos(alf), 4) + pow(sin(beta), 2) + (1.0/4) * pow(sin(2*alf), 2) - 1;
	float z = sin(beta + alf) * sin(beta - alf);
	cout << y << "	" << z << "	" << y - z << endl;
	return 0;
}
