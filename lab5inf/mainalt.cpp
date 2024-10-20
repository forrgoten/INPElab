#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int temp = 0;
    int max1, it,jt;
    int T = 0;
    int arrsize1 = 0;
    int arrsize2 = 0;
    cin>>arrsize1>>arrsize2;
    int arr[arrsize1][arrsize2];

    for (int i = 0;i<arrsize1;i++)
        {
            for (int j = 0;j<arrsize2;j++)
            {
                cin >> arr[i][j];
            }
        }
        max1 = arr[0][0];
    for (int i = 0;i<arrsize1;i++)
        {
            for (int j = 0;j<arrsize2;j++)
                {
                    if (arr[i][j] > max1)
                        {
                            max1 = arr[i][j];
                            it = i;
                            jt = j;

                        }

                        if (arr[i][j] == 0)
                            {
                                T++;
                                cout<<"indexnull"<<T<<" "<<i<<' '<<j<<endl;
                            }
                }
        }

    cout<<"nullcount "<<T<<endl;
    cout<<"max "<<max1<<endl;
    cout<<"indexmax "<<it + 1<<" "<<jt + 1<< endl;

    temp = arr[0][0];
    arr[0][0] = arr[it][jt];
    arr[it][jt] = temp;

    cout << arr[0][0] << " <=> " << arr[it][jt];
    return 0;
}
