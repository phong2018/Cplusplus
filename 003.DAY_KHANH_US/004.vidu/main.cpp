#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main () {
  /*Khai báo biến */
  int i;
  float f;
  char c;
  string str;// char str[80]; đều được
  ofstream fout;
  ifstream finp;
  string mytext;
  /*Đọc từ file*/
finp.open ("D:/2018/025.DAY-THEM/026.day phuong anh c++/003.DAY_KHANH_US/004.vidu/input.inp");
  while (getline (finp, mytext)) {
  // Output the text from the file
  cout << mytext<<"\n";
}
   
}