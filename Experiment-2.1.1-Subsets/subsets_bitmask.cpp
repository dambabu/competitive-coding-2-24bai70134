#include <iostream>
#include <vector>
using namespace std;

// LeetCode #78 - Subsets
// Experiment 2.1: Subsets
// Approach: Iterative Bit Manipulation

vector<vector<int>> subsetsBitmask(const vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> subset;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }

        result.push_back(subset);
    }

    return result;
}

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
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsetsBitmask(nums);

    cout << "Input: [1,2,3]\n";
    cout << "Number of subsets: " << result.size() << "\n";
    cout << "Output: ";
    printSubsets(result);

    return 0;
}
