#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed,
                       vector<int>& efficiency, int k) {

        vector<pair<int, int>> engineers;

        // Store efficiency and speed together
        for (int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }

        // Sort engineers by decreasing efficiency
        sort(engineers.rbegin(), engineers.rend());

        // Min-heap to keep the highest speeds
        priority_queue<int, vector<int>, greater<int>> minHeap;

        long long speedSum = 0;
        long long result = 0;

        const int MOD = 1000000007;

        for (auto &eng : engineers) {

            int eff = eng.first;
            int spd = eng.second;

            minHeap.push(spd);
            speedSum += spd;

            // Keep at most k engineers
            if (minHeap.size() > k) {
                speedSum -= minHeap.top();
                minHeap.pop();
            }

            // Performance = total speed × minimum efficiency
            result = max(result, speedSum * eff);
        }

        return result % MOD;
    }
};

int main() {

    int n, k;

    cin >> n;

    vector<int> speed(n);
    vector<int> efficiency(n);

    // Input speeds
    for (int i = 0; i < n; i++) {
        cin >> speed[i];
    }

    // Input efficiencies
    for (int i = 0; i < n; i++) {
        cin >> efficiency[i];
    }

    cin >> k;

    Solution obj;

    cout << obj.maxPerformance(n, speed, efficiency, k);

    return 0;
}