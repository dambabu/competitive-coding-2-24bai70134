#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numIslands(vector<vector<char>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    int count = 0;

    // Four possible directions
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            // If land is found
            if (grid[r][c] == '1')
            {
                count++;

                // Queue stores row and column
                queue<pair<int, int>> q;

                q.push({r, c});

                // Mark as visited by changing 1 -> 0
                grid[r][c] = '0';

                while (!q.empty())
                {
                    int currentR = q.front().first;
                    int currentC = q.front().second;

                    q.pop();

                    // Check four directions
                    for (int i = 0; i < 4; i++)
                    {
                        int newR = currentR + dr[i];
                        int newC = currentC + dc[i];

                        // Check boundaries
                        if (newR >= 0 && newR < m &&
                            newC >= 0 && newC < n &&
                            grid[newR][newC] == '1')
                        {
                            grid[newR][newC] = '0';

                            q.push({newR, newC});
                        }
                    }
                }
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