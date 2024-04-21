//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int capacity, int weight[], int value[], int i, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (weight[i] <= capacity)
                return value[i];
            return 0;
        }

        if (dp[capacity][i] != -1)
            return dp[capacity][i];

        int include = 0;
        if (weight[i] <= capacity)
            include = value[i] + solve(capacity - weight[i], weight, value, i - 1, dp);
        int exclude = solve(capacity, weight, value, i - 1, dp);

        return dp[capacity][i] = max(include, exclude);
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
        return solve(W, wt, val, n - 1, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
// } Driver Code Ends