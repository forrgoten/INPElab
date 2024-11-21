#include <iostream>

using namespace std;

void print_arr(int array[], size_t size)
{
   while (size--)
   {
      cout<<" "<<*array++;
   }
   cout << endl;
}

int is_seq(const int* x, const int* y)
{
   return ((*x) * (*y) < 0);
}

int last_seq(int array[], size_t size, int** begin, int** end)
{
   int* cur = array + size - 1;

   for (; (array < cur) && !is_seq(cur, cur - 1); --cur) { ; }
   *end = cur;

   for (; (array < cur) && is_seq(cur, cur - 1); --cur) { ; }
   *begin = cur;

   return *end - *begin;
}

size_t rmlastseq(int array[], size_t size)
{
   int* begin;
   int* end;

   int len = 0;

   if ((len = last_seq(array, size, &begin, &end)) > 0)
   {
      end++;
      len++;

      array += size;

      while (end < array)
      {
         *begin++ = *end++;
      }
   }

   return size - len;
}

int main()
{
    int arrsize=0;
    cin >> arrsize;
    int arr[arrsize];
    for(int i = 0;i < arrsize;i++)
        {
            cin >> arr[i];
        }
        print_arr(arr, rmlastseq(arr, arrsize));
    return 0;
}
