#include "hashT.h"
#include<iostream>
#include<fstream>
#include<string>
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
