#include <iostream>
using namespace std;

// Function to calculate the number of ways
int climbStairs(int n) {
    // Base cases
    if (n <= 2) {
        return n;
    }

    // ways(1) = 1, ways(2) = 2
    int prev1 = 1;
    int prev2 = 2;

    // Calculate ways from 3 to n
    for (int i = 3; i <= n; i++) {
        int current = prev1 + prev2;

        // Move to the next two values
        prev1 = prev2;
        prev2 = current;
    }

    return prev2;
}

int main() {
    int n;

    cout << "Enter the number of stairs: ";
    cin >> n;

    cout << "Number of distinct ways: "
         << climbStairs(n) << endl;

    return 0;
}