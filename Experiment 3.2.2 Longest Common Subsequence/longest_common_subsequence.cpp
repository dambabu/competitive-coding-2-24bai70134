#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to find the length of the Longest Common Subsequence
int longestCommonSubsequence(string text1, string text2) {

    int m = text1.size();
    int n = text2.size();

    // Create DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            // If characters are equal
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            // If characters are different
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {

    // Test Case 1
    string text1 = "abcde";
    string text2 = "ace";

    cout << "Test Case 1" << endl;
    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;
    cout << "LCS Length: "
         << longestCommonSubsequence(text1, text2) << endl;

    cout << endl;

    // Test Case 2
    text1 = "abc";
    text2 = "abc";

    cout << "Test Case 2" << endl;
    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;
    cout << "LCS Length: "
         << longestCommonSubsequence(text1, text2) << endl;

    cout << endl;

    // Test Case 3
    text1 = "abc";
    text2 = "def";

    cout << "Test Case 3" << endl;
    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;
    cout << "LCS Length: "
         << longestCommonSubsequence(text1, text2) << endl;

    return 0;
}