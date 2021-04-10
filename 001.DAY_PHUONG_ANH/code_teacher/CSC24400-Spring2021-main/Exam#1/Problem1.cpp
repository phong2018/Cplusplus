#include <cstdlib>
#include <iostream>

using namespace std;

int countOdds(int values[], int size)
{
  if (size <=0)
    return 0;

  if (values[size-1] %2 ==1)
    return 1+countOdds(values, size-1);
  else
    return countOdds(values, size-1);
}

int main(int argc, char *argv[])
{
  int *arr;
  arr = new int[argc-1];
  for (int index=1; index<argc; index++)
    {
      arr[index-1] = atoi(argv[index]);
    }

  cout << countOdds(arr, argc-1) << endl;
}
