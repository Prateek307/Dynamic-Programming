// link to the problem ---> https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(int i, string s, vector<int> &dp)
    {
        if (i >= s.size())
            return 1;

        if (s[i] == '0')
            return 0;

        if (i == s.size() - 1)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        if (s[i] == '1' || (s[i] == '2' && (s[i + 1] >= 48 && s[i + 1] <= 54)))
            return dp[i] = (solve(i + 1, s, dp) % mod + solve(i + 2, s, dp) % mod) % mod;

        else
            return dp[i] = solve(i + 1, s, dp) % mod;
    }

    int CountWays(string str)
    {
        // Code here
        vector<int> dp(str.size() + 1, -1);
        return solve(0, str, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.CountWays(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends