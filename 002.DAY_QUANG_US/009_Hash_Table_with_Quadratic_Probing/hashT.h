#include<string>
#include<iostream>
#include <sstream>
using namespace std;
#ifndef HASHT_H
#define HASHT_H

template <class elemType>
class hashT
{
public:
	hashT(int size = 101);

	void insert(const elemType& rec);

	int search(const elemType& rec, bool& found) const;


	void remove(const elemType& rec);

	string print() const;

	~hashT();
private:

	int nextProbingPlace(int place_now, int probing_time) const;

	int hashFunction(const elemType& key) const;

	bool isItemAtEqual(int hashIndex, const elemType& rec) const;



	private:
	elemType *HTable; //pointer to the hash table
	int *indexStatusList; //pointer to the array indicating the
	//status of a position in the hash table
	int length; //number of items in the hash table
	int HTSize; //maximum size of the hash table
};
#endif

template <class elemType>
int hashT<elemType>::hashFunction(const elemType& key) const
{


	ostringstream oss;
	oss<<key;
	string key_str = oss.str();
	int sum = 0;
	for (int j = 0; j < key_str.size(); j++)
		sum = sum + static_cast<int>(key_str.at(j));
	return (sum % HTSize);
}

template <class elemType>
int hashT<elemType>::nextProbingPlace(int place_now, int probing_time) const
{
	int result = (place_now+probing_time*probing_time)%HTSize; //prepared for quadratic probing
	//int result = (place_now+1)%HTSize;
	return result;
}

template <class elemType>
bool hashT<elemType>::isItemAtEqual(int hashIndex, const elemType& rec) const
{
	//cout<<"Inside"<<indexStatusList[hashIndex]<<endl;
	if(hashIndex<0 || hashIndex>=HTSize || indexStatusList[hashIndex]==0 )
		return false;

	return HTable[hashIndex] == rec;
}

template <class elemType>
hashT<elemType>::hashT(int size)
{
	if(size<=0)
		size = 101;
	HTSize = size;
	length = 0;
	HTable = new elemType[HTSize];
	indexStatusList = new int[HTSize];
	for(int i=0;i<HTSize;i++)
		indexStatusList[i] = 0;
}



template <class elemType>
void hashT<elemType>::insert( const elemType& rec)
{
	int pCount = 1;
	int inc = 1;
	int hashIndex = hashFunction(rec);
	while (indexStatusList[hashIndex] == 1
	&& HTable[hashIndex] != rec && pCount < HTSize / 2)
	{
		hashIndex = nextProbingPlace(hashIndex, pCount);
		pCount++;
	}
	if (indexStatusList[hashIndex] != 1)
	{
		HTable[hashIndex] = rec;
		indexStatusList[hashIndex] = 1;
		length++;
	}
	else if(HTable[hashIndex] == rec)
		cerr << "Error: No duplicates are allowed." << endl;
	else
		cerr << "Error: The table is full. "
		<< "Unable to resolve the collision." << endl;
}



//linear probing
template <class elemType>
int hashT<elemType>::search(const elemType& rec, bool& found) const
{
	int pCount = 1;
	int inc = 1;
	int hashIndex = hashFunction(rec);
	while (!isItemAtEqual(hashIndex, rec) && pCount < HTSize / 2)
	{
		hashIndex = nextProbingPlace(hashIndex, pCount);
		pCount++;
	}
	if(isItemAtEqual(hashIndex, rec))
		found = true;
	else
		found = false;
	return pCount;
}

template <class elemType>
void hashT<elemType>::remove(const elemType& rec)
{
	int pCount = 0;
	int inc = 1;
	int hashIndex = hashFunction(rec);
	while (!isItemAtEqual(hashIndex, rec) && pCount < HTSize / 2)
	{
		hashIndex = nextProbingPlace(hashIndex, pCount);
		pCount++;
	}
	if(isItemAtEqual(hashIndex, rec))
	{
		indexStatusList[hashIndex] = 0;
		length --;
	}
}

template <class elemType>
string hashT<elemType>::print() const
{
	string result;
	for(int i=0;i<HTSize;i++)
	{
		if(indexStatusList[i]==1)
		{
			if(result!="")
				result += " ";
			stringstream ss;
			ss<<HTable[i];
			string temp;
			ss>>temp;
			result += temp;
		}
	}
	return result;
}

template <class elemType>
hashT<elemType>::~hashT()
{
	delete[] HTable;
	delete[] indexStatusList;
}
//quadratic probing
/*template <class elemType>
void hashT<elemType>::insert(int hashIndex, const elemType& rec)
{
	int pCount;
	int inc;
	pCount = 0;
	inc = 1;
	while (indexStatusList[hashIndex] == 1
	&& HTable[hashIndex] != rec && pCount < HTSize / 2)
	{
		pCount++;
		hashIndex = (hashIndex + inc) % HTSize;
		inc = inc + 2;
	}
	if (indexStatusList[hashIndex] != 1)
	{
		HTable[hashIndex] = rec;
		indexStatusList[hashIndex] = 1;
		length++;
	}
	else if(HTable[hashIndex] == rec)
		cerr << "Error: No duplicates are allowed." << endl;
	else
		cerr << "Error: The table is full. "
		<< "Unable to resolve the collision." << endl;

}*/
