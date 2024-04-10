/*
Problem Statement

Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
*/

// link to the problem ---> https://www.naukri.com/code360/problems/ninja-s-training_3621003

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&v , int row , int last,vector<vector<int>> &dp)
{
    if(row==0)
    {
        int ans = 0,i;
        for(i=0;i<3;i++)
        {
            if(i!=last)
            ans = max(ans,v[0][i]);
        }
        return ans;
    }

    if(dp[row][last]!=-1)
    return dp[row][last];

    int i,cost = 0;
    for(i=0;i<3;i++)
    {
        if(i!=last)
        cost = max(cost,v[row][i] + solve(v,row-1,i,dp));
    }

    return dp[row][last] = cost;
}

int main()
{
    int n, m = 3;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(m));
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(4,-1));
    cout<<solve(v,n-1,3,dp)<<'\n';
    return 0;
}