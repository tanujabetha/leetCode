#ifndef MATRIX_BUILD_H
#define MATRIX_BUILD_H

#include<vector>
#include<iostream>
using namespace std;

class MatrixBuild {
public:
    int nodes;
    int edges;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adj;
    vector<int> visited;
    int flag;

    MatrixBuild(int nodes, int edges, int flag);

    int adjacencyMatrix();
    void printAdjacencyMatrix();
    int adjacencyList();
    void printAdjacencyList();
};

#endif