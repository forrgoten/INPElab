#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    ofstream {"exmp.bin"};
    srand((unsigned) time(NULL));
    int data[20];
    ofstream wf("exmp.bin", ios::out|ios::binary);
    for(int i = 0;i < 20; i++)
        data[i] = -200 + (rand() % 400);

    for(int i=0; i<20; i++)
        wf.write((char*) &data[i], sizeof(int));
    wf.close();
}
