// link to the problem ---> https://leetcode.com/problems/unique-paths/description/

// recursive solution

class Solution
{
public:
    int solve(int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if (i >= n || j >= m)
            return 0;

        else if (i == n - 1 && j == m - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = solve(i + 1, j, n, m, dp) + solve(i, j + 1, n, m, dp);
        return dp[i][j] = ans;
    }
    int uniquePaths(int m, int n)
    {
        int i, j;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};

// iterative solution
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        int i,j;
        vector<vector<int>> dp(m,vector<int>(n,-1));

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0 && j==0)
                dp[i][j] = 1;

                else
                {
                    int left = 0,right = 0;
                    if(i>0)
                    left = dp[i-1][j];
                    if(j>0)
                    right = dp[i][j-1];

                    dp[i][j] = left + right;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
*/
