// Experiment 2.3.1
// Add Digits
// LeetCode Problem #258

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {

        // Special case: 0 remains 0
        if (num == 0) {
            return 0;
        }

        // Digital root formula
        return 1 + (num - 1) % 9;
    }
};

int main() {

    Solution solution;

    // Test case 1
    int num = 38;

    int answer = solution.addDigits(num);

    cout << "Experiment 2.3.1: Add Digits" << endl;
    cout << "Input: " << num << endl;
    cout << "Digital Root: " << answer << endl;

    return 0;
}