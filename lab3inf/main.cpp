#include <iostream>

using namespace std;

int main()
{
    float x,y;
    cin >> x >> y;
    if((y < 1 - x*x && y>0 && y<1) || (x < 0 && x > -1 && y>0 && y - x < 1))
        {
            cout << "YES";
        }
    else
        {
            cout << "NO";
        }
    return 0;
}
