// link to the problem ---> https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, int n, int m, vector<vector<int>> &v,vector<vector<int>> &dp)
{
    if (i >= n || j >= m || v[i][j]==1)
        return 0;

    else if (i == n - 1 && j == m - 1)
        return 1;

    if(dp[i][j]!=-1)
    return dp[i][j];

    return dp[i][j] = (solve(i + 1, j, n, m,v,dp) + solve(i, j + 1, n, m,v,dp));

}
int main()
{

    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int> (m));
    vector<vector<int>>dp(n+1,vector<int> (m+1,-1));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>v[i][j];
    }
    cout<<solve(0,0,n,m,v,dp)<<'\n';
    return 0;
}


//leetcode Submission
// class Solution {
// public:
// int solve(int i, int j, int n, int m, vector<vector<int>> &v,vector<vector<int>> &dp)
// {
//     if (i >= n || j >= m || v[i][j]==1)
//         return 0;

//     else if (i == n - 1 && j == m - 1)
//         return 1;

//     if(dp[i][j]!=-1)
//     return dp[i][j];

//     return dp[i][j] = (solve(i + 1, j, n, m,v,dp) + solve(i, j + 1, n, m,v,dp));

// }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//     int n = obstacleGrid.size();
//     int m = obstacleGrid[0].size();
//     vector<vector<int>>dp(n+1,vector<int> (m+1,-1));
//     return solve(0,0,n,m,obstacleGrid,dp);
//     }
// };