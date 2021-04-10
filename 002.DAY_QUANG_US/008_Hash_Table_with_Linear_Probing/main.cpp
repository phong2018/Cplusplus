#include "hashT.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

using namespace std;


int main()
{


  ifstream f;
  /*Đọc từ file*/
  f.open ("input.inp");


	//ifstream f(file_name);

	string line;
	hashT<int> h(3000);
	while(getline(f, line))
	{
		int now = atoi(line.c_str());
		h.insert(now);
	}

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int target;
		cin>>target;
		bool found;
		int ac_time = h.search(target, found);
		if(found)
			cout<<"The number is included.\n";
		else
			cout<<"The number is not included.\n";
		cout<<"Access time is: "<<ac_time<<endl;
	}

}

/*
26.9 Hash Table with Linear Probing
Introduction

In this lab, you are supposed to implement a templated Hash Table class.

class hashT

The templated class hashT, with templated type elemType should have four private member variables:

elemType *HTable The array that contains the elements
int *indexStatusList The array indicating the status of each slot
int length; The number of elements added.
int HTSize; The maximum size of the HTable.
Methods below are needed as well:

hashT(int size = 101); The constructor. Create the arrays HTTable and indexStatusList, then size of both of them would be given by the parameter size; initialize each element of the array indexStatusList to 0; length = 0 (hash table is empty); HTSize = size; and the default array size is 101.

void insert(const elemType& rec); Function to insert an item in the hash table. The item to be inserted is specified by the parameter rec. Postcondition: If an empty position is found in the hash table, rec is inserted and the length is incremented by one; otherwise, an appropriate error message is displayed.

int search(const elemType& rec, bool& found) const; Function to determine whether the item specified by the parameter rec is in the hash table. The function returns the number of access before the method returns. Postcondition: If rec is found, found is set to true; otherwise, found is set to false.

void remove(const elemType& rec); Function to remove an item from the hash table. Postcondition: If rec is found in the table it is removed; otherwise, an appropriate error message is displayed.

string print() const; Function to output the data, return the output in the form of string, with all elements in the hash table included and each seperated by a space.

int hashFunction(elemType key); Hash function that returns the hashed value of the input.

~hashT(); The destructor.

The following private methods are already offered to you in the template:

-- bool isItemAtEqual(int hashIndex, const elemType& rec) const; Function to determine whether the item specified by the parameter rec is the same as the item in the hash table at position hashIndex. Postcondition: Returns true if HTable[hashIndex] == rec; otherwise, returns false.

-- int hashFunction(const elemType& rec) const; This function returns the hash index for a given element rec.

-- int nextProbingPlace(int placenow, int probingtime) const; This function helps you find where the next place is to look into to find out where rec is.

main function

In the main function, you are supposed to read in a file whose name is given through the stream, in which each line is an integer. The file contains over 1000 but less than 1500 elements. Insert all the elements given in the file. Read in an integer n from the stream first, then read in n integers from the stream and judge whether each of them is included. When a number is given, print "The number is included.\n" if it is in the hash table; otherwise, print "The number is not included.\n" Besides, for each number given, print the total access time before knowing search method returns in the following format: "Access time is: #". Replace the '#' with the access number in that case.
*/
