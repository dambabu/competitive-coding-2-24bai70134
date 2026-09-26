#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid,
         vector<vector<bool>>& visited,
         int r, int c,
         int m, int n)
{
    // Check boundaries
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    // Stop if water or already visited
    if (grid[r][c] == '0' || visited[r][c])
        return;

    // Mark as visited
    visited[r][c] = true;

    // Up
    dfs(grid, visited, r - 1, c, m, n);

    // Down
    dfs(grid, visited, r + 1, c, m, n);

    // Left
    dfs(grid, visited, r, c - 1, m, n);

    // Right
    dfs(grid, visited, r, c + 1, m, n);
}

int numIslands(vector<vector<char>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // Separate visited matrix
    vector<vector<bool>> visited(
        m, vector<bool>(n, false)
    );

    int count = 0;

    // Scan every cell
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            // New island found
            if (grid[r][c] == '1' && !visited[r][c])
            {
                count++;

                dfs(grid, visited, r, c, m, n);
            }
        }
    }

    return count;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    int result = numIslands(grid);

    cout << "Number of Islands: " << result << endl;

    return 0;
}