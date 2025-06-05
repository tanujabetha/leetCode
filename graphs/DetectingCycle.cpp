#include "DetectingCycle.h"
#include <vector>
#include <iostream>
// adj[0] = {1}
// adj[1] = {0, 2, 4}
// adj[2] = {1, 3}
// adj[3] = {2, 4}
// adj[4] = {1, 3}

//(0,-1)->(1,0)->(2,1)->(3,2)->(4,3)->1 is visited, so we check fr parent that is 3 here,how come we have 1 visited already(Cyle is detected, becuase for 4 the parent is 3, and for 1 the parent was 0)

// In an undirected graph, if during DFS we reach a visited node
// that is not the parent of the current node, then we've found a back edge — which forms a cycle.

// If I visit a neighbor that's already visited and it's not my parent,
//  I've looped back through a different path — that's a cycle.

// 1-2-3-1

DetectingCycle::DetectingCycle(int nodes, int edges)
{
    this->nodes = nodes;
    this->cycleVisited = vector<int>(nodes, -1);
    this->directedVisited = vector<int>(nodes, -1);
    this->pathVisited =vector<int>(nodes,-1);

}

bool DetectingCycle::detectUndirectedGraphCycleDFS(int vertex, int parent, vector<vector<int>> &adj)
{
    cout << "Checking for vertex: " << vertex << "\n";
    cycleVisited[vertex] = 1;
    for (auto neigh : adj[vertex])
    {
        cout << "Checking for neighbour: " << neigh << "\n";
        if (cycleVisited[neigh] != 1)
        {
            if (detectUndirectedGraphCycleDFS(neigh, vertex,adj))
            {
                return true;
            }
        }
        else
        {
            cout << neigh << " is already visited, is it same as parent" << parent << "\n";
            if (neigh != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool DetectingCycle::detectUndirectedGraphCycleBFS(int vertex,vector<vector<int>> &adj)
{
    queue<int> bfsCycle;
    vector<pair<int, int>> cyclebfsVisit(nodes, {-1, -1});
    cout<<"Checking for vertex: \n "<<vertex;
    bfsCycle.push(vertex);
    cyclebfsVisit[vertex] = make_pair(vertex, -1);
    while (!bfsCycle.empty())
    {
        int node = bfsCycle.front();
        int parent = cyclebfsVisit[node].second;
        cout<<"vertex looked is: "<<node<<" with parent as"<<parent<<"\n";
        bfsCycle.pop();
        for (int neighbour : adj[node])
        {
            cout<<"Checking for neighbour: "<<neighbour<<"\n";
            if (cyclebfsVisit[neighbour].first != 1)
            {
                cyclebfsVisit[neighbour] = make_pair(1, node);
                bfsCycle.push(neighbour);
            }
            else
            {
                if (neighbour != parent) // is the neighbour not my parent, then if he is visited, there is a differnt way to reach him than through me.
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// Check the path visited it if is already visited in the path
bool DetectingCycle::detectDirectedGraphCycleDFS(int vertex, int parent)
{
    cout << "Vertex being visited: " << vertex << "\n";

    directedVisited[vertex] = 1;
    cout<<vertex<<" visited "<<directedVisited[vertex];
    pathVisited[vertex] = 1;

    for (int neighbour : adj[vertex])
    {
        cout<<"Neighbour is: "<<neighbour;
        if (directedVisited[neighbour] != 1)
        {
            if (detectDirectedGraphCycleDFS(neighbour, vertex))
            {
                return true;
            }
        }
        else
        {
            if (pathVisited[neighbour] == 1)
            {
                // Back edge found
                cout << "Back edge to " << neighbour << " detected from " << vertex << "\n";
                return true;
            }
        }
    }

    // Done exploring current path
    pathVisited[vertex] = -1;
    return false;
}
