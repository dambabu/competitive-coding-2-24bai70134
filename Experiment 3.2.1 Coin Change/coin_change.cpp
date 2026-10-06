#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the minimum number of coins
int coinChange(vector<int>& coins, int amount) {

    // dp[i] represents the minimum number of coins
    // needed to make amount i
    vector<int> dp(amount + 1, amount + 1);

    // Base case
    dp[0] = 0;

    // Calculate answer for every amount from 1 to amount
    for (int a = 1; a <= amount; a++) {

        // Try every coin
        for (int c : coins) {

            if (c <= a) {
                dp[a] = min(dp[a], dp[a - c] + 1);
            }
        }
    }

    // If amount cannot be formed, return -1
    if (dp[amount] <= amount) {
        return dp[amount];
    }

    return -1;
}

int main() {

    // Test Case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;

    cout << "Test Case 1" << endl;
    cout << "Coins: [1, 2, 5]" << endl;
    cout << "Amount: 11" << endl;
    cout << "Minimum coins: "
         << coinChange(coins1, amount1) << endl;

    cout << endl;

    // Test Case 2
    vector<int> coins2 = {2};
    int amount2 = 3;

    cout << "Test Case 2" << endl;
    cout << "Coins: [2]" << endl;
    cout << "Amount: 3" << endl;
    cout << "Minimum coins: "
         << coinChange(coins2, amount2) << endl;

    cout << endl;

    // Test Case 3
    vector<int> coins3 = {1};
    int amount3 = 0;

    cout << "Test Case 3" << endl;
    cout << "Coins: [1]" << endl;
    cout << "Amount: 0" << endl;
    cout << "Minimum coins: "
         << coinChange(coins3, amount3) << endl;

    cout << endl;

    // Test Case 4
    vector<int> coins4 = {1, 3, 4};
    int amount4 = 6;

    cout << "Test Case 4" << endl;
    cout << "Coins: [1, 3, 4]" << endl;
    cout << "Amount: 6" << endl;
    cout << "Minimum coins: "
         << coinChange(coins4, amount4) << endl;

    cout << endl;

    // Test Case 5
    vector<int> coins5 = {2, 5, 10, 1};
    int amount5 = 27;

    cout << "Test Case 5" << endl;
    cout << "Coins: [2, 5, 10, 1]" << endl;
    cout << "Amount: 27" << endl;
    cout << "Minimum coins: "
         << coinChange(coins5, amount5) << endl;

    return 0;
}