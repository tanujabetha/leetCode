#ifndef DETECT_CYCLE_H
#define DETECT_CYCLE_H
#include <vector>
using namespace std;
class DetectingCycle
{
public:
    vector<int> cycleVisited;
    vector<int> directedVisited;
    vector<int> pathVisited;
    vector<vector<int>> adj; 

    int nodes; 
    int edges;
    
    DetectingCycle(int nodes, int edges);


    bool detectUndirectedGraphCycleDFS(int vertex, int parent,vector<vector<int>> &adj);
    bool detectUndirectedGraphCycleBFS(int vertex,vector<vector<int>> &adj);
    bool detectDirectedGraphCycleBFS();
    bool detectDirectedGraphCycleDFS(int vertex, int parent);
};

#endif