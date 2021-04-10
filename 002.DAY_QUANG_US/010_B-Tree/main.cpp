// C++ program for B-Tree insertion
#include<iostream>
#include "bTree.h"

using namespace std;

int main()
{
	int minDegree, numOfKey, key;

	cin >> minDegree;
	BTree<int> tree(minDegree);

	cin >> numOfKey;
	while (numOfKey) {
		cin >> key;
		tree.insert(key);
		numOfKey = numOfKey - 1;
	}

	cout << "Preorder traverse:" << endl;;
	tree.traverse();

	return 0;
}
