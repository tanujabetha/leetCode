#include <iostream>
#include <vector>
#include "MatrixBuild.h"
#include "Traversals.h"
using namespace std;



Traversals::Traversals(int nodes, int edges, int flag):MatrixBuild(nodes,edges, flag)
{
    visited = vector<int>(nodes, 0);
}

void Traversals::dfsTraversal(int vertex)
{
    visited[vertex] = 1;
    cout << vertex << " " << "\n";
    for (auto v : adj[vertex])
    {
        if (visited[v] != 1) // I'm checking if the node is already not visited, only then I want to traverse
        {
            dfsTraversal(v);
        }
    }
}

void Traversals::bfsTraversal(int start)
{
    visited = vector<int>(nodes, 0);  // Reset visited array
    queue<int> bfs;
    //check the start
    visited[start] = 1;
    bfs.push(start);
    while(!bfs.empty())
    {
        int vertex = bfs.front();
        bfs.pop();
        cout<<vertex<<" ";
        for(auto neighbour: adj[vertex])
        {
            if(visited[neighbour]!=1)
            {
                bfs.push(neighbour);
                visited[neighbour] = 1;
            }
        }
    }
}
