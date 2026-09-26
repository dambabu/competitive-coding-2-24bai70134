#include <iostream>
#include <vector>

using namespace std;

bool bruteForceDFS(int current, int destination,
                   vector<vector<int>>& adj,
                   vector<bool>& visited)
{
    // If current node is destination
    if (current == destination)
        return true;

    // Mark current node as visited
    visited[current] = true;

    // Try every neighbour
    for (int neighbour : adj[current])
    {
        if (!visited[neighbour])
        {
            if (bruteForceDFS(neighbour, destination, adj, visited))
                return true;
        }
    }

    return false;
}

bool validPath(int n, vector<vector<int>>& edges,
               int source, int destination)
{
    // Create adjacency list
    vector<vector<int>> adj(n);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);

    return bruteForceDFS(source, destination, adj, visited);
}

int main()
{
    int n = 3;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}
    };

    int source = 0;
    int destination = 2;

    bool result = validPath(n, edges, source, destination);

    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}