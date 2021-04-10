#include "linkedList.h"
#include "queue.h"
#include <fstream>
#include <sstream>
#include<iostream>
#include<string>
using namespace std;
#ifndef GRAPH_H
#define GRAPH_H



class graph
{
protected:
	linkedList<int> *adjacentVertices;
	int numVertices;
	int maxNumVertices;

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
	string depthFirstTraversal();
	//Function to perform the depth first traversal of the entire graph. Return a string with vertice id in the order of visit.

	string breadthFirstTraversal();
	//Function to perform the breadth first traversal of the entire graph. Return a string with vertice id in the order of visit.

   string bfTopOrder();
   //Returns string of nodes in topological order

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
	maxNumVertices = n;
	adjacentVertices = new linkedList<int>[maxNumVertices];
	numVertices = 0;
}

graph::~graph()
{
	if(!isEmpty())
		clearGraph();
}

bool graph::isEmpty() const
{
	return numVertices==0;
}

void graph::createGraph(string file_name)
{
	ifstream f(file_name);
	if(f.fail())
		return;
	string line;
	getline(f, line);
	int num = stoi(line);
	numVertices = num;
	for(int i=0;i<numVertices;i++)
	{
		getline(f, line);
		//analyze and get each adjacent vertice
		stringstream ss(line);
		string temp;
		while(ss>>temp)
		{
			int v = stoi(temp);
			adjacentVertices[i].insertLast(v);
		}
	}
}

void graph::clearGraph()
{
	for(int i=0;i<numVertices;i++)
	{
		adjacentVertices[i].destroyList();
	}
	numVertices = 0;
}

string graph::printGraph() const
{
	string result = to_string(numVertices)+"\n";
	for(int i=0;i<numVertices;i++)
	if(adjacentVertices[i].begin()!=NULL)
	{
		result += adjacentVertices[i].print()+"\n";
	}
	else
	   result += "\n";
	return result;
}

string graph::depthFirstTraversal()
{
	bool *visited = new bool[numVertices];
	for(int i=0;i<numVertices;i++)
		visited[i] = false;
	return rec_dft(0, visited);
	//return "";
}

string graph::rec_dft(int vertice_now,bool *visited)
{
	if(visited[vertice_now]||vertice_now>=numVertices)
		return "";
	string result = "";
	result += to_string(vertice_now)+" ";
	visited[vertice_now] = true;
	auto iter = adjacentVertices[vertice_now].begin();
	while(iter!=adjacentVertices[vertice_now].end())
	{
		result += rec_dft(iter->info, visited);
		iter = iter->link;
	}
	return result;
}

string graph::breadthFirstTraversal()
{
	if(isEmpty())
		return "";
	queue<int> q;
	bool *visited = new bool[numVertices];
	for(int i=0;i<numVertices;i++)
		visited[i] = false;
	q.enqueue(0);
	string result = "";
	while(!q.is_empty())
	{
		int vertice_now = q.front();
		q.dequeue();
		if(visited[vertice_now])
			continue;
		visited[vertice_now] = true;
		result += to_string(vertice_now)+" ";
		auto iter = adjacentVertices[vertice_now].begin();
		while(iter!=adjacentVertices[vertice_now].end())
		{
			q.enqueue(iter->info);
			iter = iter->link;
		}
	}
	return result;
}


string graph::bfTopOrder()
{
   string result;
   queue<int> bfqueue;
   int *topologicalOrder; //pointer to the array to store breadth first topological ordering
   topologicalOrder = new int[numVertices];
   int topIndex = 0;
   nodeType<int> *graphIt;
   int *predCount; //pointer to the array to store the predecessor count of a vertex.
   predCount = new int[numVertices];

   int ind = 0;

   for (ind = 0; ind < numVertices; ind++)
      predCount[ind] = 0;
   //Determine the predecessor count of all the vertices.
   for (ind = 0; ind < numVertices; ind++)
   {
      for (graphIt = adjacentVertices[ind].begin(); graphIt != NULL; graphIt=graphIt->link)
      {
         int w = graphIt->info;
         predCount[w]++;
      }
   }

   for (ind = 0; ind < numVertices; ind++)
      if (predCount[ind] == 0)
         bfqueue.enqueue(ind);

   while (!bfqueue.is_empty())
   {
      int u = bfqueue.front();
      bfqueue.dequeue();
      topologicalOrder[topIndex++] = u;

      for (graphIt = adjacentVertices[u].begin(); graphIt != NULL; graphIt=graphIt->link)
      {
         int w = graphIt->info;
         predCount[w]--;
         if (predCount[w] == 0)
         bfqueue.enqueue(w);
      }
   }//end while
   //output the vertices in breadth first topological order
   result = to_string(topologicalOrder[0]);
   for (ind = 1; ind < numVertices; ind++)
      result += " " + to_string(topologicalOrder[ind]);
   cout << endl;
   delete [] topologicalOrder;
   delete [] predCount;
   return result;
}


