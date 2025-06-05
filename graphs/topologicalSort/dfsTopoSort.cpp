#include <iostream>
#include <vector>
using namespace std;

void topologicalSortDFS( int vertex,vector<int> &visited, vector<vector<int>> &adj, stack<int> &topoSort)
{

    //I'm marking you as visited
    visited[vertex] = 1;
    cout << vertex << " visited " << visited[vertex]<<endl;

    for (int neighbour : adj[vertex])
    {
        if(visited[neighbour]!=1)
        {
            topologicalSortDFS(neighbour, visited, adj, topoSort);
        }
    }

    // Done checking the vertext childs. Since recursion in top down, if there is v connected to vertex, that would already have been in 
    // added to the stack. Since my dependents are already added, I'm adding myself now.
    topoSort.push(vertex);

}

int main()
{

    int nodes, edges;
    cout << "Enter number of vertices and edges: \n";
    cin >> nodes >> edges;
    vector<int> visited(nodes, -1);
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
    stack<int> topoSort;
    //Incase of garph components
    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] != 1)
        {
            topologicalSortDFS(i, visited, adj, topoSort);
        }
    }
    cout<<"Printing the topo sort"<<endl;

    while(!topoSort.empty())
    {
        cout<<topoSort.top()<<" ";
        topoSort.pop();
    }
    return 0;
}