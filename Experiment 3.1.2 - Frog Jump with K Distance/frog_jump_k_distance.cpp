#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// Function to calculate minimum cost
int minCost(vector<int>& height, int k) {
    int n = height.size();

    // dp[i] = minimum cost to reach stone i
    vector<int> dp(n, 0);

    // Calculate minimum cost for each stone
    for (int i = 1; i < n; i++) {
        int best = 1000000000;

        // Check the previous k stones
        for (int j = max(0, i - k); j < i; j++) {
            int cost = dp[j] + abs(height[i] - height[j]);
            best = min(best, cost);
        }

        dp[i] = best;
    }

    return dp[n - 1];
}

int main() {
    int n, k;

    cout << "Enter the number of stones: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter the heights of the stones: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << "Enter the maximum jump distance k: ";
    cin >> k;

    cout << "Minimum total cost: "
         << minCost(height, k) << endl;

    return 0;
}