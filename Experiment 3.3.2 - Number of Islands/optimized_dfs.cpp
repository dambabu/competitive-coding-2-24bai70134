#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid,
         int r, int c,
         int m, int n)
{
    // Check boundaries
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    // Stop if current cell is water
    if (grid[r][c] != '1')
        return;

    // Sink the land
    grid[r][c] = '0';

    // Up
    dfs(grid, r - 1, c, m, n);

    // Down
    dfs(grid, r + 1, c, m, n);

    // Left
    dfs(grid, r, c - 1, m, n);

    // Right
    dfs(grid, r, c + 1, m, n);
}

int numIslands(vector<vector<char>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    int count = 0;

    // Scan entire grid
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] == '1')
            {
                // New island
                count++;

                // Sink entire island
                dfs(grid, r, c, m, n);
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
