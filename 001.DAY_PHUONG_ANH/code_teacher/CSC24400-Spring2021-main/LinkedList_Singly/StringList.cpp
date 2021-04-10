#include "StringList.hpp"

using namespace std;

void
StringList::insert(const string &someVal)
{
  StringNode *newNode = new StringNode(someVal);

  newNode->next() = _head;

  _head = newNode;

  if (_tail == NULL) // started with an empty list (aka this is the first item)
    _tail = newNode;
}

void
StringList::append(const std::string &someVal)
{
  if (_tail==NULL) //nothing in list right now. (note: means head is null too)
    {
      // inserting at front would get this done as well.
      insert(someVal);
      return;
    }

  // only way we can get here is if _tail was not null.
  
  StringNode *newNode = new StringNode(someVal);
  
  newNode->next() = NULL;
  
  _tail->next()=newNode;
  
  _tail=newNode;

}


StringNode*
StringList::removeFront()
{
  if (_head==NULL)
    {
      cerr << "Attempt to remove from head of empty list!!!" << endl;
      return NULL;
    }

  if (_head==_tail) // _head was not null (see above), so this tests for 1 node
    {
      _tail=NULL; // rest of code updates _head appropriately
    }
  
  StringNode *nodePtr;

  nodePtr=_head;

  _head=_head->next();
  
  return nodePtr;
}

StringNode*
StringList::findPrev(StringNode *someNode)
{
  StringNode *currPtr = _head;
  while(currPtr->next() != someNode)
    currPtr = currPtr->next();

  return currPtr;
}

StringNode*
StringList::removeTail() 
{
  if (_head->next() == NULL) // is this a 1 node list?
    {
      StringNode *answer = _head;
      _head=_tail=NULL;
      return answer;
    }
  else // >1 node in list
    {
      StringNode *answer = _tail;
      StringNode *prev = findPrev(_tail);
      _tail=prev;
      _tail->next()=NULL; // alternatively: prev->next()=NULL;
      return answer;
    }
}

ostream&
StringList::print(ostream& os) const
{
  StringNode *currPtr;

  currPtr=_head;

  while(currPtr!=NULL)
    {
      os << *currPtr << endl;

      currPtr = currPtr->next();
    }

  return os;
}

ostream& operator<<(ostream &os, const StringList &sl)
{
  return sl.print(os);
}
