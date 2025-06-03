#include <iostream>
#include <vector>
#include "MatrixBuild.h"
#include "Traversals.h"
using namespace std;
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
            flag = 1; // Directed trav
        else
            flag = 0; // Undirected trav

        Traversals trav(nodes, edges, flag);
        int start;

        switch (choice)
        {
        case 1:
            trav.adjacencyMatrix();
            cout << "Printing Undirected Adjacency Matrix:\n";
            trav.printAdjacencyMatrix();
            // cout << "Print DFS traversal:\n";
          
            // cout << "Enter the starting node for traversal: ";
            // cin >> start;

            // if (start >= 0 && start < nodes)
            // {
            //     cout << "Printing DFS Traversal:" << "\n";
            //     trav.dfsTraversal(start);
            //     cout << "Printing BFS Traversal:" << "\n";
            //     trav.bfsTraversal(start);
            // }
            // else
            // {
            //     cout << "Invalid start node.\n";
            // }

            break;

        case 2:
            cout<<"Adjacency List:\n"; 
            trav.adjacencyList();
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
            // cout << "Print DFS traversal:\n";
           
            // cout << "Enter the starting node for traversal: ";
            // cin >> start;

            // if (start >= 0 && start < nodes)
            // {
            //     cout << "Printing DFS Traversal:" << "\n";
            //     trav.dfsTraversal(start);
            //     cout << "Printing BFS Traversal:" << "\n";
            //     trav.bfsTraversal(start);
            // }
            // else
            // {
            //     cout << "Invalid start node.\n";
            // }
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

        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
