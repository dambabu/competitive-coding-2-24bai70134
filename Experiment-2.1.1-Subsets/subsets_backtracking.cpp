#include <iostream>
#include <vector>
using namespace std;

// LeetCode #78 - Subsets
// Experiment 2.1: Subsets
// Approach: Backtracking

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start,
                   vector<int>& current,
                   vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = start; i < (int)nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};

void printSubsets(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j + 1 < result[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < result.size()) cout << ",";
    }
    cout << "]\n";
}

int main() {
    Solution solution;

    vector<vector<int>> testCases = {
        {1, 2, 3},
        {0},
        {1, 2},
        {7},
        {4, 5, 6, 7}
    };

    for (const auto& test : testCases) {
        vector<int> nums = test;
        vector<vector<int>> result = solution.subsets(nums);

        cout << "Input: [";
        for (size_t i = 0; i < nums.size(); ++i) {
            cout << nums[i];
            if (i + 1 < nums.size()) cout << ",";
        }
        cout << "]\n";

        cout << "Number of subsets: " << result.size() << "\n";
        cout << "Output: ";
        printSubsets(result);
        cout << "\n";
    }

    return 0;
}
