#include <iostream>
#include <vector>

using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rankValue;

public:

    // Constructor
    DSU(int n)
    {
        parent.resize(n);
        rankValue.resize(n, 0);

        // Initially every node is its own parent
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find parent of a node
    int find(int x)
    {
        if (parent[x] == x)
            return x;

        // Path compression
        return parent[x] = find(parent[x]);
    }

    // Join two sets
    void unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        // Already in same set
        if (rootA == rootB)
            return;

        // Union by rank
        if (rankValue[rootA] < rankValue[rootB])
        {
            parent[rootA] = rootB;
        }
        else if (rankValue[rootA] > rankValue[rootB])
        {
            parent[rootB] = rootA;
        }
        else
        {
            parent[rootB] = rootA;
            rankValue[rootA]++;
        }
    }

    // Check whether two nodes belong
    // to the same connected component
    bool connected(int a, int b)
    {
        return find(a) == find(b);
    }
};

bool validPath(int n, vector<vector<int>>& edges,
               int source, int destination)
{
    DSU dsu(n);

    // Join all connected nodes
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        dsu.unite(u, v);
    }

    // Check whether source and destination
    // belong to the same component
    return dsu.connected(source, destination);
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