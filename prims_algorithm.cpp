#include <iostream>
#include <vector>

using namespace std;

#define V 5

/* 2 ways of Graph representation:
1. Adjacency List (can be done using list or vector) - vector <vector<pii>> where pii : typedef pair <int,int> pii (i.e. [[ [], [], [] ] ...]) {node, edge weight}
2. Adjaceny matrix - 2 dimensional
*/

/*
Chooses a vertex which provides the smallest edge cut to an existing vertex.
(minimum weight of any edge that connects a vertex not yet included in the MST to the subset of vertices already included in the MST.)
*/
int minVertex(int keys[], bool mstVertices[], int size)
{

    int min = __INT_MAX__, min_idx = - 1;
    for (int i = 0; i < size; i++)
    {

        if (!mstVertices[i] && keys[i] <= min)
        {
            min = keys[i], min_idx = i;
        }
    }
    return min_idx;
}

void prims(int graph[V][V], int vertices)
{

    // all the vertices included in the MST
    bool mstVertices[vertices];

    int keys[vertices]; // all the edges part of the cut
    int parent[vertices];

    for (int i = 0; i < vertices; i++)
    {
        keys[i] = __INT_MAX__;
        mstVertices[i] = false;
    }

    keys[0] = 0; // first vertex has 0 cost to get picked.

    for (int i = 0; i < vertices - 1; i++)
    {
        int u = minVertex(keys, mstVertices, vertices);
        mstVertices[u] = true;

        for (int v = 0; v < vertices; v++)
        {
            if (graph[u][v] && !mstVertices[v] && graph[u][v] < keys[v])
            {
                parent[v] = u;
                keys[v] = graph[u][v];
            }
        }
    }

    /*
    parent[i] represents the vertex which was used to add the vertex i to the MST. (ex: i = 1 & parent[1] = 0 => 1 was added thru 0)
    */

    cout << "Edge \tWeight\n";
    for (int i = 1; i < vertices; i++)
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
    }
}

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    int vertices = V;
    prims(graph, vertices);

    return 0;
}

/*

Simple array: O(V^2)
PQ + adj list: O((V + E) log V)

*/