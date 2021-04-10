#include<string>
#include<iostream>
#include <sstream>
using namespace std;
#ifndef HASHT_H
#define HASHT_H
//=========
template <class elemType>
class hashT{
public:
	hashT(int size = 101){
        cout<<HTSize<<endl;
        cout<<length<<endl;
	};
	void insert(const elemType& rec){
	    cout<<"insert:"<<rec<<endl;
	    int index =1;
	    //index = hashFunction(rec);
	    cout<<index<<endl;
        /*
        while(indexStatusList[index] != 0)
        index = (index + 1) % HTSize;
        HTable[index] = rec;
        */

	};
	int search(const elemType& rec, bool& found) const{
	    cout<<"search:"<<rec<<endl;
	};
	void remove(const elemType& rec){
	    cout<<"remove:"<<rec<<endl;
	};
	string print() const{
	    cout<<"printr"<<endl;
	};
	~hashT(){};
private:
	int nextProbingPlace(int place_now, int probing_time) const;
	int hashFunction(const elemType& key) const;
	bool isItemAtEqual(int hashIndex, const elemType& rec) const;
	private:
	elemType *HTable; //pointer to the hash table
	int *indexStatusList; //pointer to the array indicating the status of a position in the hash table
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
	int result = (place_now+1)%HTSize;
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
int main(){
    hashT<int> h;
    bool found;
    h.insert(1);
    h.search(1,found);
    h.remove(1);
    h.print();
}

