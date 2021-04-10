#include <iostream>
#include "linkedList.h"

using namespace std;

int main() {
    linkedList<int> linklist;
    linklist.insert(2);
    linklist.insert(3);
    linklist.insert(4);
    linklist.print();

   return 0;
}
