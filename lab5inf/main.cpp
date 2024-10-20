#include <iostream>
using namespace std;

int main()
{

    int max1,max2;
    int arrsize=0;
    cin >> arrsize;
    int arr[arrsize];
    for(int i = 0;i < arrsize;i++)
        {
            cin >> arr[i];
        }
    max1=arr[0];
    for (int i=0; i<arrsize/2; i++)
        { if (arr[i]>max1)
          max1=arr[i];
    }

     max2=arr[arrsize/2];
    for (int i=arrsize/2; i<arrsize; i++)
        { if (arr[i]>max2)
          max2=arr[i];
    }
    cout<<max1<<endl;
    cout<<max2<<endl;
    return 0;
}
