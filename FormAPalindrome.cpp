// link to the problem ---> https://www.geeksforgeeks.org/problems/form-a-palindrome2544/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int solve(int i, int j, int n, string s, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;

        if (s[i] == s[j])
            dp[i][j] = solve(i + 1, j - 1, n, s, dp);

        if (dp[i][j] != -1)
            return dp[i][j];

        else
            dp[i][j] = 1 + min(solve(i + 1, j, n, s, dp), solve(i, j - 1, n, s, dp));

        return dp[i][j];
    }

    int findMinInsertions(string S)
    {
        // code here
        vector<vector<int>> dp(S.size() + 1, vector<int>(S.size() + 1, -1));
        return solve(0, S.size() - 1, S.size(), S, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMinInsertions(S) << endl;
    }
    return 0;
}

// } Driver Code Ends