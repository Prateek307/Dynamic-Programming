// link to the problem ---> https://leetcode.com/problems/triangle/description/

// class Solution
// {
// public:
//     int solve(int i, int j, vector<vector<int>> &triangle, int n, int m)
//     {
//         if (i >= n)
//             return INT_MAX;

//         if (i == n - 1)
//             return triangle[i][j];

//         return triangle[i][j] + min(solve(i + 1, j, triangle, n, m), solve(i + 1, j + 1, triangle, n, m));
//     }
//     int minimumTotal(vector<vector<int>> &triangle)
//     {
//         int n = triangle.size(), m = triangle[0].size();
//         return solve(0, 0, triangle, n, m);
//     }
// };

// using recursive approach
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); // Initialize dp with INT_MAX

    // Initialize the bottom row of dp
    for (int j = 0; j < n; ++j) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Update dp from second-to-last row to the first row
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    // The top-left element of dp will contain the minimum total
    return dp[0][0];
    }
};
