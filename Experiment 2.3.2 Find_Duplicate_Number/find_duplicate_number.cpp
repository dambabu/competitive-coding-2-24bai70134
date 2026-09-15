// Experiment 2.3.2
// Find the Duplicate Number
// LeetCode Problem #287

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Phase 1: Find the meeting point
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];

        } while (slow != fast);

        // Phase 2: Find the entrance of the cycle
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {

    Solution solution;

    // Test case
    vector<int> nums = {1, 3, 4, 2, 2};

    int answer = solution.findDuplicate(nums);

    cout << "Experiment 2.3.2: Find the Duplicate Number" << endl;

    cout << "Input: ";
    for (int value : nums) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Duplicate Number = " << answer << endl;

    return 0;
}