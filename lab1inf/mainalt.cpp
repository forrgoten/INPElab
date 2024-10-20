#include <cmath>
#include <stdio.h>

using namespace std;


int main()
{
    float alf, beta;
    printf("Input1\n");
    scanf("%f", &alf);
    printf("Input2\n");
    scanf("%f", &beta);
    float y = pow(cos(alf), 4) + pow(sin(beta), 2) + (1.0/4) * pow(sin(2*alf), 2) - 1;
    float z = sin(beta + alf) * sin(beta - alf);
    printf("%f\t%f\t%f\t", y,z,y-z);
    return 0;
}
