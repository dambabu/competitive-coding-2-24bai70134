#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool validPath(int n, vector<vector<int>>& edges,
               int source, int destination)
{
    // Step 1: Create adjacency list
    vector<vector<int>> adj(n);

    // Step 2: Add edges
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 3: Source and destination are same
    if (source == destination)
        return true;

    // Step 4: Visited array
    vector<bool> visited(n, false);

    // Step 5: Create queue
    queue<int> q;

    // Step 6: Start BFS from source
    q.push(source);
    visited[source] = true;

    // Step 7: BFS traversal
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // Check all neighbours
        for (int neighbour : adj[node])
        {
            // Destination found
            if (neighbour == destination)
                return true;

            // If not visited
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    // Path does not exist
    return false;
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