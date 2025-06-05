#include <iostream>
#include <vector>
#include "MatrixBuild.h"
#include "Traversals.h"
#include "DetectingCycle.h"
using namespace std;

int main()
{
    int choice;
    vector<vector<int>> adj;

    while (true)
    {
        cout << "\n--- Graph Representation Menu ---\n";
        cout << "1. Undirected Adjacency Matrix\n";
        cout << "2. Undirected Adjacency List\n";
        cout << "3. Directed Adjacency Matrix\n";
        cout << "4. Directed Adjacency List\n";
        cout << "5. Undirected Graph Cycle detection in DFS\n";
        cout << "6. Undirected Graph Cycle detection in BFS\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 8)
        {
            cout << "Exiting...\n";
            break;
        }

        int flag;
        if (choice >= 3)
            flag = 1; // Directed trav
        else
            flag = 0; // Undirected trav

        int nodes, edges;
        if (choice >= 1 & choice <= 4)
        {
            cout << "Enter the number of nodes and edges: ";
            cin >> nodes >> edges;
        }

        Traversals trav(nodes, edges, flag);
        DetectingCycle cyc(nodes, edges);
        cyc.adj = trav.adj;

        int start;

        switch (choice)
        {
        case 1:
            trav.adjacencyMatrix();
            cout << "Printing Undirected Adjacency Matrix:\n";
            trav.printAdjacencyMatrix();
            break;

        case 2:
            cout << "Adjacency List:\n";
            trav.adjacencyList();
            adj = trav.adj;
            cout << "Printing Undirected Adjacency List:\n";
            trav.printAdjacencyList();
            cout << "Print DFS traversal:\n";

            cout << "Enter the starting node for traversal: ";
            cin >> start;

            if (start >= 0 && start < nodes)
            {
                cout << "Printing DFS Traversal:" << "\n";
                trav.dfsTraversal(start);
                cout << "Printing BFS Traversal:" << "\n";
                trav.bfsTraversal(start);
            }
            else
            {
                cout << "Invalid start node.\n";
            }
            break;

        case 3:
            trav.adjacencyMatrix();
            cout << "Printing Directed Adjacency Matrix:\n";
            trav.printAdjacencyMatrix();
            break;

        case 4:
            trav.adjacencyList();
            cout << "Printing Directed Adjacency List:\n";
            trav.printAdjacencyList();
            cout << "Print DFS traversal:\n";
            cout << "Enter the starting node for traversal: ";
            cin >> start;

            if (start >= 0 && start < nodes)
            {
                cout << "Printing DFS Traversal:" << "\n";
                trav.dfsTraversal(start);
                cout << "Printing BFS Traversal:" << "\n";
                trav.bfsTraversal(start);
            }
            else
            {
                cout << "Invalid start node.\n";
            }
            break;

        case 5:
            cout << "In undirected, we check if I reached the same node from a different path. That is if I was visited before then I should be be you parent.\n There should not be anu other path that is coming from you to me.\n Think 1-2-3.\n If 1 are parent is -1\n 2 parent is 1\n 3 parent is 2\n If 3 goes back to 1, there is a cycle here, as 1 is not the parent of 3.\n";
            cout << "Enter the starting node for traversal: \n";
            cin >> start;

            if (start >= 0 && start < nodes)
            {
                bool hasCycle = cyc.detectUndirectedGraphCycleDFS(start, -1, adj);
                if (hasCycle)
                {
                    cout << "Cycle detected\n";
                }
                else
                {
                    cout << "No cycle detected\n";
                }
            }
            else
            {
                cout << "Invalid start node.\n";
            }
            break;

        case 6:
            cout << "In undirected, we check if I reached the same node from a different path.That is if I was visited before then I should be be you parent.\n There should not be any other path that is coming from you to me.\n Think 1 - 2 - 3.\n If 1 are parent is - 1\n 2 parent is 1\n 3 parent is 2\n If 3 goes back to 1,there is a cycle here, as 1 is not the parent of 3. ";
            cout << "Enter the starting node for traversal: \n";
            cin >> start;
            cyc.adj = trav.adj;

            cout << adj.size();
            cout << "\n";
            if (start >= 0 && start < nodes)
            {
                if (cyc.detectUndirectedGraphCycleBFS(start, adj))
                {
                    cout << "Cycle has been detected\n";
                }
                else
                {
                    cout << "Cycle not been detected\n";
                }
            }
            else
            {
                cout << "Invalid start node.\n";
            }
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }
    }

    return 0;
}
