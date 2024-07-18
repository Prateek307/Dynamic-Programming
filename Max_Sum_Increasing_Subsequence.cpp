// link to the problem ---> https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int solve(int i, int v[], vector<int> &dp)
    {
        if (i == 0)
            return v[0];

        if (dp[i] != -1)
            return dp[i];

        int ans = v[i], j;
        for (j = 0; j < i; j++)
        {
            if (v[j] < v[i])
                ans = max(ans, solve(j, v, dp) + v[i]);
        }
        return dp[i] = ans;
    }

    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        int i, ans = 0;
        vector<int> dp(n + 1, -1);
        for (i = 0; i < n; i++)
        {
            ans = max(ans, solve(i, arr, dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends