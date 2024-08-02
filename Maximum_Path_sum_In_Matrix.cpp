// link to the problem ---> https://www.geeksforgeeks.org/problems/path-in-matrix3805/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int i, int j, int n, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (i == n - 1)
        {
            if (j >= 0 && j < n)
                return arr[i][j];
            return INT_MIN;
        }
        if (j < 0 || j > n - 1)
            return INT_MIN;

        // Return the stored result if already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // Compute the maximum sum for all three possible moves
        int path1 = arr[i][j] + solve(i + 1, j, n, arr, dp);
        int path2 = arr[i][j] + solve(i + 1, j - 1, n, arr, dp);
        int path3 = arr[i][j] + solve(i + 1, j + 1, n, arr, dp);

        // Store the result and return it
        return dp[i][j] = max({path1, path2, path3});
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int ans = INT_MIN;

        // Compute the maximum path sum starting from each column in the first row
        for (int j = 0; j < N; j++)
        {
            ans = max(ans, solve(0, j, N, Matrix, dp));
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
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
}
// } Driver Code Ends