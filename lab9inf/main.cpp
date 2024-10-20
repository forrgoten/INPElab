#include <iostream>
#include <fstream>
using namespace std;

int main()
    {
        int max1, max2;
        max1=max2=0;
        int data[20];
        ifstream rf("exmp.bin", ios::in|ios::binary);
        for (int i=0; i<20; i++)
            rf.read((char*) &data[i], sizeof(int));
        rf.close();
        int datasorted[20];
        int curr = 0;
        for(int i = 0;i<20;i++)
        {
            if(data[i] % 2 == 0)
            {
                datasorted[curr] = data[i];
                curr++;
            }

        }
        for(int i = 0;i < 20;i++)
        {
            if(data[i] % 2 != 0)
            {
                datasorted[curr] = data[i];
                curr++;
            }
        }
        for(int i = 0;i < 20;i++)
        {
            if(datasorted[i] % 2 == 0 && max1 < datasorted[i])
                max1 = i;
            if(datasorted[i] % 2 != 0 && max2 < datasorted[i])
                max2 = i;
        }
        ofstream wf;
        wf.open ("out.txt");
        wf << "max1 num " << max1 << endl << "max2 num" << max2 << endl;
        wf.close();
        return 0;
}