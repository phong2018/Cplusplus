#include<iostream>

class PartiallyFilledArray
{
private:
  int *_array;
  int _currSize;
public:

  PartiallyFilledArray();
  PartiallyFilledArray(int maxSize);

  void add(const int &toAdd);
  void operator+=(const int  &toAdd);
  void operator+=(const PartiallyFilledArray &toAdd);

  std::ostream& operator<<(std::ostream &os) const;


  int& operator[] (int index);

  // PartiallyFilledArray a, b, c;
  //   allows c=a=b;
  //       c =  a.operator=(b);

  const PartiallyFilledArray& operator=(const PartiallyFilledArray &rhs);

  std::ostream& print(std::ostream &toThisStream) const;

  //Từ khóa friend giúp truy cập trực tiếp vào dữ liệu của lớp
  friend std::ostream& operator<<(std::ostream &os,
				  const PartiallyFilledArray &pfa);
};
