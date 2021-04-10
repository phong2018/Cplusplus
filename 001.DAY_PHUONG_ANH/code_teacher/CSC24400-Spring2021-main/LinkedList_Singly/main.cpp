#include <iostream>

#include "StringList.hpp"
#include "StringNode.hpp"


using namespace std;

int main(int argc, char *argv[])
{
  StringNode someVar("Blythe");
  
  cout << someVar << endl;

  cout << "==== end StringNode Testing ====" << endl;
  
  StringList nameList;
  nameList.insert("Blythe");
  nameList.insert("Jeevanjee");
  nameList.insert("Holland");
  nameList.insert("Garibaldi");
  nameList.insert("Kremmel");
  nameList.insert("Goncalves");

  cout << nameList;
  cout << "===== END OF NAMES LIST =====" << endl;

  nameList.append("Sailor");
  nameList.append("Gehner");

  cout << nameList;
  cout << "===== END OF NAMES LIST =====" << endl;

  StringList evil;

  evil.append("Gates");
  cout << evil;
  cout << "===== END OF EVIL LIST =====" << endl;


  cout << "before remove:" << endl
       << nameList << endl
       << "=====================" << endl;
  cout << "REMOVED:" << *nameList.removeFront() << endl;
  cout << "REMOVED:" << *nameList.removeFront() << endl;
  cout << "REMOVED:" << *nameList.removeFront() << endl;
  cout << "REMOVED:" << *nameList.removeFront() << endl;
  cout << "REMOVED:" << *nameList.removeFront() << endl;
  cout << "REMOVED:" << *nameList.removeFront() << endl;
  cout << "REMOVED:" << *nameList.removeFront() << endl;
  cout << "REMOVED:" << *nameList.removeFront() << endl;
  
  cout << "after remove:" << endl
       << nameList << endl
       << "=====================" << endl;


  StringNode *removedNode = nameList.removeFront();
  if (removedNode!=NULL)
    cout << "REMOVED:" << *removedNode << endl;
  else
    cout << "Idiot user alert!" << endl;

  StringList sizeOne;
  sizeOne.append("Only Node");

  cout << sizeOne
       << "=====================" << endl;

  cout << "removed:" << * sizeOne.removeFront() << endl;

  cout << sizeOne
       << "=====================" << endl;

  sizeOne.append("One");
  sizeOne.append("Un");
  sizeOne.append("Uno");
  sizeOne.append("Single");
  sizeOne.append("Alone");
  sizeOne.append("Not Binary 0");

  cout << sizeOne
       << "=====================" << endl;

  cout << "Node removed:" << * sizeOne.removeTail() << endl;
  cout << "Node removed:" << * sizeOne.removeTail() << endl;
  cout << "Node removed:" << * sizeOne.removeTail() << endl;
  cout << "Node removed:" << * sizeOne.removeTail() << endl;
  cout << "Node removed:" << * sizeOne.removeTail() << endl;
  cout << "Node removed:" << * sizeOne.removeTail() << endl;
  cout << "Node removed:" << * sizeOne.removeTail() << endl;

  cout << sizeOne
       << "=====================" << endl;
  return 0;
}
