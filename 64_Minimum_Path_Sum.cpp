// link to the problem ---> https://leetcode.com/problems/minimum-path-sum/

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp)
    {
        if (i >= n || j >= m)
            return INT_MAX;

        else if (i == n - 1 && j == m - 1)
            return grid[n - 1][m - 1];

        if (dp[i][j] != INT_MAX) // Check if already computed
            return dp[i][j];

        return dp[i][j] = grid[i][j] + min(solve(i + 1, j, grid, n, m, dp), solve(i, j + 1, grid, n, m, dp));
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX)); // Initialize with INT_MAX
        return solve(0, 0, grid, n, m, dp);
    }
};


// another approach
/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX)); // Initialize with INT_MAX

        dp[n-1][m-1] = grid[n-1][m-1];
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(i == n-1 && j == m-1) continue;
                int a = (i+1 < n) ? dp[i+1][j] : INT_MAX;
                int b = (j+1 < m) ? dp[i][j+1] : INT_MAX;
                dp[i][j] = grid[i][j] + min(a, b);
            }
        }
        return dp[0][0];
    }
};

*/