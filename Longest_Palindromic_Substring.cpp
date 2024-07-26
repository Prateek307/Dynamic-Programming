// link to the problem ---> https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int solve(string s, int l, int r, vector<vector<int>> &dp)
    {
        if (l >= r)
            return 1;

        if (dp[l][r] != -1)
            return dp[l][r];

        if (s[l] == s[r])
            return dp[l][r] = solve(s, l + 1, r - 1, dp);
        else
            return 0;
    }

    string longestPalindrome(string S)
    {
        // code here
        string s = S;
        int i, j, n = s.size(), maxlen = INT_MIN, startingIndex = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; j++)
            {
                if (solve(s, i, j, dp))
                {
                    if (j - i + 1 > maxlen)
                    {
                        startingIndex = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }

        return s.substr(startingIndex, maxlen);
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
        cout << ob.longestPalindrome(S) << endl;
    }
    return 0;
}

// } Driver Code Ends