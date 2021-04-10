#include "PartiallyFilledArray.hpp"

#include <iostream>

using namespace std;

PartiallyFilledArray::PartiallyFilledArray()
{
  _array = new int[20];
  _currSize = 0;
}

PartiallyFilledArray::PartiallyFilledArray(int maxSize)
{
  _array = new int[maxSize];
  _currSize = 0;
}


void
PartiallyFilledArray::add(const int &toAdd)
{
  _array[_currSize] = toAdd;
  _currSize++;
}

void
PartiallyFilledArray::operator+=(const int &toAdd)
{
  add(toAdd);
}

void
PartiallyFilledArray::operator+=(const PartiallyFilledArray &otherPFA)
{
  for (int index=0; index < otherPFA._currSize; index++)
    {
      *this += otherPFA._array[index];
    }
}

int&
PartiallyFilledArray::operator[] (int index)
{
  if (index < _currSize)
    return _array[index];
  else
    {
      cerr << "invalid index (" << index << ") ... size is "
	   <<  _currSize << endl;
      int *answer = new int;
      return *answer;
    }
}
//Chú ý: C++ cho phép nạp chồng hàm với tham số là const chỉ khi tham số const là tham chiếu hoặc con trỏ.
const PartiallyFilledArray&
PartiallyFilledArray::operator=(const PartiallyFilledArray &rhs)
{
  _array = new int[rhs._currSize];
  // fill it in
  for (int index=0; index< rhs._currSize; index++)
    _array[index] = rhs._array[index];

  _currSize = rhs._currSize;

  return *this;
}

ostream&
PartiallyFilledArray::print(ostream &toThisStream) const
{
  for (int index=0; index<_currSize; index++)
    {
      toThisStream << *(_array+index) << endl;
    }

  return toThisStream;
}


std::ostream& operator<<(std::ostream &os, const PartiallyFilledArray &pfa)
{
  return pfa.print(os);
}
