//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int i, int j, int n, int arr[], vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int first = 0, last = 0;
        first = arr[i] + min(solve(i + 2, j, n, arr, dp), solve(i + 1, j - 1, n, arr, dp));
        last = arr[j] + min(solve(i, j - 2, n, arr, dp), solve(i + 1, j - 1, n, arr, dp));

        return dp[i][j] = max(first, last);
    }

    bool is1winner(int N, int arr[])
    {

        // code here
        int sum = 0, i, val;
        for (i = 0; i < N; i++)
            sum += arr[i];

        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        val = solve(0, N - 1, N, arr, dp);

        if (val >= (sum - val))
            return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0;
}

// } Driver Code Ends