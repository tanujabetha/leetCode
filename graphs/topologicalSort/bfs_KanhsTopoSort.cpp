#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kahnsTopoSort(vector<vector<int>> &adj)
{
    vector<int> result;
    queue<int> bfsTopo;
    vector<int> indegree(adj.size(), 0);
    // Getting the indegree
    cout << "Performing indegree\n";
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int neighbour = adj[i][j];
            indegree[neighbour]++;
        }
    }
    cout << "Printing indegree\n";
    for (int i = 0; i < indegree.size(); i++)
    {
        cout << i << " : " << indegree[i] << "\n";
    }
    cout << "Pushing all indegree to queue\n";
    // pushing all the indegree = 0 into the queue
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            bfsTopo.push(i);
        }
    }
    cout << "Performing bfs\n";
    // bfs on the queue
    while (!bfsTopo.empty())
    {
        int vertex = bfsTopo.front();
        result.push_back(vertex);
        bfsTopo.pop();
        for (auto neighbour : adj[vertex])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                bfsTopo.push(neighbour);
            }
        }
    }
    cout << "Returning\n";
    return result;
}

int main()
{

    int nodes, edges;
    cout << "Enter number of vertices and edges: \n";
    cin >> nodes >> edges;
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

    vector<int> result;

    result = kahnsTopoSort(adj);

    cout << "Printing the topo sort" << endl;
    for (auto x : result)
    {
        cout << x << " ";
    }
    return 0;
}