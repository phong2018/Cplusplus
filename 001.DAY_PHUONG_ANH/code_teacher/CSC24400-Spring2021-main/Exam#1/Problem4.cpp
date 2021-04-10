#include <cstdlib> // for rand() to fill array
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int matrix[20][15];

  
  
  // this nested loop is not part of the exam problem solution
  //    it just fills the 2D array with random numbers
  srand(time(NULL));
  for (int row=0; row<20; row++)
    for (int col=0; col<15; col++)
      matrix[row][col] = rand() % 10000;

  int sum,count;
  sum=count=0;
  
  for (int row=0; row<20; row++)
    for (int col=0; col<15; col++)
      if (matrix[row][col] %2 ==1)
	{
	  sum+=matrix[row][col];
	  count++;
	}

  cout << "odd average =" << sum/(double) count << endl;
  
  
  return 0;
}
