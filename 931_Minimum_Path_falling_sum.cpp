// link to the problem ---> https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &dp)
    {
        if (i >= n || j >= m || j < 0) // Adjusted condition for out of bounds check
            return INT_MAX;

        if (i == n - 1)
            return matrix[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int down = solve(i + 1, j, matrix, n, m, dp);
        int down_right = solve(i + 1, j + 1, matrix, n, m, dp);
        int down_left = solve(i + 1, j - 1, matrix, n, m, dp);

        return dp[i][j] = matrix[i][j] + min({down, down_right, down_left});
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;

        for (int j = 0; j < m; j++) // Fixed loop limit from n to m
        {
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
            ans = min(solve(0, j, matrix, n, m, dp), ans);
        }
        return ans;
    }
};