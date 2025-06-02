#include <iostream>
#include <vector>
using namespace std;

// Adjacency Matrix

class MatrixBuild
{
public:
    int nodes;
    int edges;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adj;
    int flag = 0;

    MatrixBuild(int nodes, int edges, int flag)
    {
        this->nodes = nodes;
        this->flag = flag;
        this->edges = edges;
        adjMatrix = vector<vector<int>>(nodes, vector<int>(nodes, -1));
        adj = vector<vector<int>>(nodes);
    }

    int adjacencyMatrix()
    {
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cout << "Enter the node, and its child ";
            cin >> u >> v;
            if (u >= nodes || v >= nodes || u < 0 || v < 0)
            {
                cout << "Invalid Request";
                cout << "\n";
                return 0;
            }
            if (flag == 1)
            {
                adjMatrix[u][v] = 1;
            }
            else
            {
                adjMatrix[u][v] = 1;
                adjMatrix[v][u] = 1;
            }
        }
        return 1;
    }

    void printAdjacencyMatrix()
    {
        for (int i = 0; i < nodes; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < nodes; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    int adjacencyList()
    {
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cout << "Enter the node, and its child ";
            cin >> u >> v;
            if (u > nodes || v > nodes)
            {
                cout << "Invalid Request";
                cout << "\n";
                return 0;
            }

            if (flag == 1)
            {
                adj[u].push_back(v);
            }
            else
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        return 1;
    }

    void printAdjacencyList()
    {
        for (int i = 0; i < nodes; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int choice;

    while (true)
    {
        cout << "\n--- Graph Representation Menu ---\n";
        cout << "1. Undirected Adjacency Matrix\n";
        cout << "2. Undirected Adjacency List\n";
        cout << "3. Directed Adjacency Matrix\n";
        cout << "4. Directed Adjacency List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5)
        {
            cout << "Exiting...\n";
            break;
        }

        int nodes, edges;
        cout << "Enter the number of nodes and edges: ";
        cin >> nodes >> edges;

        int flag;
        if (choice >= 3)
            flag = 1; // Directed graph
        else
            flag = 0; // Undirected graph

        MatrixBuild graph(nodes, edges, flag);

        switch (choice)
        {
        case 1:
            graph.adjacencyMatrix();
            cout << "Printing Undirected Adjacency Matrix:\n";
            graph.printAdjacencyMatrix();
            break;

        case 2:
            graph.adjacencyList();
            cout << "Printing Undirected Adjacency List:\n";
            graph.printAdjacencyList();
            break;

        case 3:
            graph.adjacencyMatrix();
            cout << "Printing Directed Adjacency Matrix:\n";
            graph.printAdjacencyMatrix();
            break;

        case 4:
            graph.adjacencyList();
            cout << "Printing Directed Adjacency List:\n";
            graph.printAdjacencyList();
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
