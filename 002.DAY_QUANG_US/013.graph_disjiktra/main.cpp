#include "graph.h"
#include <iostream>

using namespace std;

int main()
{
    graph g(100);
    g.createGraph("input.inp");
    //cout<<g.printGraph();
    g.findShortestPath(0,4);
    return 0;
}
