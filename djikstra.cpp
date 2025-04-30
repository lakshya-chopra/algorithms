// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>
// using namespace std;

// typedef pair<int, int> pii;

// void dijkstra(int V, vector<vector<pii>> &adj, int src)
// {
//     vector<int> dist(V, INT_MAX);
//     dist[src] = 0;

//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     pq.push({0, src}); // {distance, vertex}

//     while (!pq.empty())
//     {
//         int u = pq.top().second;
//         int d = pq.top().first;
//         pq.pop();

//         for (auto &edge : adj[u])
//         {
//             int v = edge.first;
//             int weight = edge.second;

//             if (dist[v] > d + weight)
//             {
//                 dist[v] = d + weight;
//                 pq.push({dist[v], v});
//             }
//         }
//     }

//     cout << "Shortest distances from node " << src << ":\n";
//     for (int i = 0; i < V; i++)
//     {
//         cout << "To node " << i << ": " << dist[i] << "\n";
//     }
// }

// int main()
// {
//     int V = 5;
//     vector<vector<pii>> adj(V);

//     // Add edges (u, v, w)
//     adj[0].push_back({1, 10});
//     adj[0].push_back({4, 5});
//     adj[1].push_back({2, 1});
//     adj[1].push_back({4, 2});
//     adj[2].push_back({3, 4});
//     adj[3].push_back({0, 7});
//     adj[3].push_back({2, 6});
//     adj[4].push_back({1, 3});
//     adj[4].push_back({2, 9});
//     adj[4].push_back({3, 2});

//     dijkstra(V, adj, 0);
//     return 0;
// }

#include <limits.h>
#include <stdio.h>
#include <iostream>

#define V 9

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
    std::cout << "min: " << min << std::endl;

    for (int v = 0; v < V; v++)

        if (sptSet[v] == false && dist[v] <= min)
        {
            std::cout << "dist[v]: " << dist[v] << std::endl;
            min = dist[v], min_index = v;
        }

    return min_index;
}

void printSolution(int dist[], int n)
{
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("\t%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array. dist[i] will hold the
                 // shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX, sptSet[i] = false;
        std::cout << "dist[i]: " << dist[i] << std::endl;
    }
    // Originally all distances from src = Inf & NO vertex is visited

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true; // mark as visited. If initially we were checking the vertex 0, then it will be marked as true, also the first u would equal 0.
        std::cout << "min returned: " << u << std::endl;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)
        {
            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to v through u is
            // smaller than current value of dist[v]
            // std::cout << sptSet[v] << std::endl;

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                std::cout << "dist[u]: " << dist[u] << std::endl;
                std::cout << "v: " << v << std::endl;
                std::cout << "u: " << u << std::endl;
                dist[v] = dist[u] + graph[u][v]; // distance from the src , dist[u] = 0
            }
        }
    }

    printSolution(dist, V);
}

int main()
{
    // adjacency matrix    
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}

/*

Simple array: O(V^2)
PQ + adj list: O((V + E) log V)

*/