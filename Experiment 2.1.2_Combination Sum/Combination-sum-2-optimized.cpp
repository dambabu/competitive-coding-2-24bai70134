#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& candidates, int start, vector<int>& current,
               int remaining, vector<vector<int>>& result)
{
    if (remaining == 0)
    {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); i++)
    {
        if (candidates[i] > remaining)
            break;

        current.push_back(candidates[i]);

        backtrack(candidates, i, current,
                  remaining - candidates[i], result);

        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> result;
    vector<int> current;

    sort(candidates.begin(), candidates.end());

    backtrack(candidates, 0, current, target, result);

    return result;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    for (const auto& combination : result)
    {
        cout << "[";

        for (int i = 0; i < combination.size(); i++)
        {
            cout << combination[i];

            if (i < combination.size() - 1)
                cout << ",";
        }

        cout << "]\n";
    }

    return 0;
}
