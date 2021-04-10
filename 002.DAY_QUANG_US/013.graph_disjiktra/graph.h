#include "linkedList.h"
#include <fstream>
#include <sstream>
#include<iostream>
#include<string>
using namespace std;
#ifndef GRAPH_H
#define GRAPH_H
#define vc 2000000



class graph
{
protected:
	linkedList<int> *adjacentVertices,*adjacentCost ;
	int numVertices,numedge;//so dinh, so canh do thi

public:
	graph(int n = 100); //Constructor, initializes the parameters with maximum vertices given, default to be 100
	bool isEmpty() const;
	//Function to determine whether the graph is empty. Returns true if it is, otherwise, returns false;
	void createGraph(string file_name);
	//Function to create a graph based on a file, whose name is file_name.
	void clearGraph();
	//Function to clear graph. Allocate all memories occupied by vertices
	string printGraph() const;
	//Function to return the graph as a string in adjacent list format.

    string findShortestPath(int start, int end); //return the shortest path from "start" to "end".

	~graph();
	//Destructor. The storage occupied by the vertices is deallocated.

private:
	string rec_dft(int vertice_now, bool *visited);


};
#endif

graph::graph(int n)
{
	if(n<=0)
		n=100;
	numVertices = n;
	adjacentVertices = new linkedList<int>[numVertices];
	adjacentCost= new linkedList<int>[numVertices];
	numedge=0;
}

graph::~graph()
{
	if(!isEmpty())
		clearGraph();
}

//===========
string graph::findShortestPath(int start, int end){
    int f[numVertices],check[numVertices],trace[numVertices],i,fmin;
    for(i=0;i<numVertices;i++){
        f[i]=vc;check[i]=0;trace[i]=0;
    }
    //----khởi tạo đỉnh xuất phát
    f[start]=0;
    trace[start]=start;
    i=0;
    while(i> -1){
        // tìm i có fmin
        fmin=vc;i=-1;
        for(int j=0;j<numVertices;j++)
        if(check[j]==0 && f[j]<fmin){i=j;fmin=f[j];}
        //--------
        if(i>-1){
            check[i]=1;
            auto tj = adjacentVertices[i].begin();
            auto tc = adjacentCost[i].begin();

            while(tj!=adjacentVertices[i].end()){
                 int j=tj->info;int c=tc->info;
                 if(f[j]>f[i]+c){f[j]=f[i]+c;trace[j]=i;}
                 tj = tj->link;tc = tc->link;
            }
        }
    }
    //xuat kq
     string result;
    if(isEmpty()){ result="The target and the source are not connected.";}
    else
    if(f[end]==vc)  result="The target and the source are not connected.";
    else{
        result=to_string(end);
        i=end;
        while(i!=trace[i]){
            i=trace[i];
            result=to_string(i)+" "+result;
        }

    }

    return result;


}

bool graph::isEmpty() const
{
	return numedge==0;
}

void graph::createGraph(string file_name)
{
	ifstream f(file_name);
	if(f.fail())return;
	f>>numVertices;
	numedge=0;
    int u,v,c;
	while(!f.eof()){
        f>>u>>v>>c;
        numedge++;
        adjacentVertices[u].insertLast(v);
        adjacentCost[u].insertLast(c);
        //if(numedge>=7) break;
	}
}

void graph::clearGraph()
{
	for(int i=0;i<numVertices;i++)
	{
		adjacentVertices[i].destroyList();
		adjacentCost[i].destroyList();
	}
	numVertices = 0;
	numedge=0;
}

string graph::printGraph() const
{
	string result = to_string(numVertices)+"\n";
	for(int i=0;i<numVertices;i++){
        auto tj = adjacentVertices[i].begin();
        auto tc = adjacentCost[i].begin();
		while(tj!=adjacentVertices[i].end()){
             int j=tj->info;int c=tc->info;
			 result=result +to_string(i)+ " " + to_string(j)+ " " + to_string(c) +"\n";
			 tj = tj->link;tc = tc->link;
		}
	}
	return result;
}


