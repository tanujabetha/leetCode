#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "MatrixBuild.h"
#include <iostream>
#include <vector>
using namespace std;

class Traversals : public MatrixBuild
{
public:
    vector<int> visited;
    // void dfsTraversal(vector<vector<int>> &adjList, vector<int> &visited, int vertex);
    // void bfsTraversal(vector<vector<int>> &adjList, vector<int> &visited, int start);
    Traversals(int nodes, int edges, int flag);

    void dfsTraversal(int vertex);
    void bfsTraversal(int start);
};

#endif
