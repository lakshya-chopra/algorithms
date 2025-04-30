#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{

    int vertices;
    vector<vector<int>> adjLists; // directed graph
    vector<bool> visited;

public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        adjLists.resize(vertices);
        visited.resize(vertices, false);
    }
    void addEdge(int src, int dest)
    {

        this->adjLists[src].push_back(dest);
    }

    void DFS(int start)
    {

        visited[start] = true;
        cout << start << " ";

        for (auto i = adjLists[start].begin(); i < adjLists[start].end(); i++)
        { // for (int i: adjLists[start])
            if (!visited[*i])
            {
                DFS(*i);
            }
        }
    }

    void BFS(int start)
    {

        vector<bool> visited(this->vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for (int i : adjLists[curr])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);

    /*
    adj List ex: [ [1,2] , [3] ]
    */

    cout << "DFS:" <<endl;
    g.DFS(2);


    cout << "\nBFS:" <<endl;
    g.BFS(0);

    return 0;
}

/*
BFS & DFS:

Adjacency List: O(V + E)
Matrix : O (V^2)

*/