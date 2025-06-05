#include <iostream>
#include <vector>
using namespace std;

bool detectDirectedGraphCycleDFS(int vertex, int parent, vector<int> &directedVisited, vector<int> &pathVisited, vector<vector<int>> &adj)
{
    cout << "Vertex being visited: " << vertex << "\n";
    directedVisited[vertex] = 1;
    cout << vertex << " visited " << directedVisited[vertex];
    pathVisited[vertex] = 1;

    for (int neighbour : adj[vertex])
    {
        cout << "Neighbour is: " << neighbour;
        if (directedVisited[neighbour] != 1)
        {
            if (detectDirectedGraphCycleDFS(neighbour, vertex, directedVisited, pathVisited, adj))
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

int main()
{

    int nodes, edges;
    cout << "Enter number of vertices and edges: \n";
    cin >> nodes >> edges;
    vector<int> directedVisited(nodes, -1);
    vector<int> pathVisited(nodes, -1);
    vector<vector<int>> adj(nodes);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter the vertex u from which the edge should be connected to v: \n";
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << "The graph is as below:\n";
    for (int i = 0; i < nodes; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Enter the start node: \n";
    int startnode;
    cin >> startnode;
    // if(detectDirectedGraphCycleDFS(startnode, -1, directedVisited, pathVisited,adj))
    // {
    //     cout<<"Cycle detected";
    // }
    // else{
    //     cout<<"Cycle not detected";
    // }


    //Incase of garph components
    for (int i = 0; i < nodes; i++)
    {
        if (directedVisited[i] != 1)
        {
            if (detectDirectedGraphCycleDFS(startnode, -1, directedVisited, pathVisited, adj))
            {
                cout << "Cycle detected";
            }
            else
            {
                cout << "Cycle not detected";
            }
        }
    }
    return 0;
}