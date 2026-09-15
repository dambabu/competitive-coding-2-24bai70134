#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void solve(vector<int>& candidates,
           int remaining,
           vector<int>& current,
           set<vector<int>>& result)
{
    if (remaining == 0)
    {
        vector<int> temp = current;
        sort(temp.begin(), temp.end());
        result.insert(temp);
        return;
    }

    if (remaining < 0)
        return;

    for (int candidate : candidates)
    {
        current.push_back(candidate);

        solve(candidates,
              remaining - candidate,
              current,
              result);

        current.pop_back();
    }
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<int> current;
    set<vector<int>> result;

    solve(candidates, target, current, result);

    cout << "Combinations that sum to " << target << ":\n";

    for (const vector<int>& combination : result)
    {
        cout << "[";

        for (int i = 0; i < combination.size(); i++)
        {
            cout << combination[i];

            if (i != combination.size() - 1)
                cout << ",";
        }

        cout << "]\n";
    }

    return 0;
}
