// link to the problem --->https://www.naukri.com/code360/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>
int solve(int i, int j, vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &dp)
{
    if (i >= n || j >= m || j < 0) // Adjusted condition for out of bounds check
        return INT_MIN;

    if (i == n - 1)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = solve(i + 1, j, matrix, n, m, dp);
    int down_right = solve(i + 1, j + 1, matrix, n, m, dp);
    int down_left = solve(i + 1, j - 1, matrix, n, m, dp);

    return dp[i][j] = matrix[i][j] + max({down, down_right, down_left});
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = INT_MIN;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int j = 0; j < m; j++) // Fixed loop limit from n to m
    {
        ans = max(solve(0, j, matrix, n, m, dp), ans);
    }
    return ans;
}