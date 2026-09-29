#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:

    int bfs(vector<vector<int>>& grid, int row, int col) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        // Start BFS from the current land cell
        q.push({row, col});

        // Mark as visited
        grid[row][col] = 0;

        int area = 0;

        // Four possible directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            // Get front cell
            auto current = q.front();
            q.pop();

            int r = current.first;
            int c = current.second;

            // Count this land cell
            area++;

            // Check all four directions
            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check boundaries and whether it is land
                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    grid[nr][nc] == 1) {

                    // Mark as visited
                    grid[nr][nc] = 0;

                    // Add to queue
                    q.push({nr, nc});
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        // Traverse the complete grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                // If land is found
                if (grid[i][j] == 1) {

                    // Find area using BFS
                    int area = bfs(grid, i, j);

                    // Update maximum area
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};

int main() {

    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1}
    };

    Solution obj;

    int result = obj.maxAreaOfIsland(grid);

    cout << "Maximum Area of Island = " << result << endl;

    return 0;
}