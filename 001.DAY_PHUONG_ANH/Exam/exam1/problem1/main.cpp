#include <iostream>

#include "PartiallyFilledArray.hpp"

using namespace std;

int countOdds(PartiallyFilledArray arr, int n){
  //condition to stop, no element
  if(n==0) return 0;
  //conditon to recursion
  if(arr[n-1]%2==1) return countOdds(arr, n-1)+1;
  else return countOdds(arr, n-1);
}

int main(int argc, char *argv[])
{
  PartiallyFilledArray arr(50);
  arr+= 1;
  arr+= 6;
  arr+= 4;
  arr+= 8;
  arr+= 7;
  arr+= 19;
  //cout<<arr;
  cout<<"the number of odd numbers: "<<countOdds(arr,6);

  return 0;
}
