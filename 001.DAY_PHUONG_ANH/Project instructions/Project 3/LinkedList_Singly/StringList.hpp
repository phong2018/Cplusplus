#ifndef _STRING_LIST_HPP_
#define _STRING_LIST_HPP_

#include <iostream>
#include <string>

#include "StringNode.hpp"

class StringList
{
private:
  StringNode *_head;
  StringNode *_tail;

  StringNode *findPrev(StringNode *someNode);
public:
  StringList() : _head(NULL), _tail(NULL) {}

  void insert(const std::string &someVal);//add frond

  void append(const std::string &someVal);//add last

  StringNode* removeFront();
  StringNode* removeTail();

  std::ostream& print(std::ostream& os) const;

  friend std::ostream& operator<<(std::ostream &os, const StringList &sl);

};

#endif
