// link to the problem ---> https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std;

int f(int i , int j1,int j2 ,int r , int c ,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp)
{
    if(j1<0 || j2<0 || j1>=c || j2>=c)
    return -1e8;

    if(i==r-1)
    {
        if(j1==j2)
        return grid[i][j1];
        else
        return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1)
    return dp[i][j1][j2];


    // explore all the possibilities
    int ans = -1e8;
    for(int dj1 = -1;dj1<=1;dj1++)
    {
        for(int dj2 = -1 ; dj2<=1 ;dj2++)
        {
            int value = 0;
            if(j1==j2)
            value = grid[i][j1];
            else
            value = grid[i][j1] + grid[i][j2];
            value+=f(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
            ans = max(ans,value);
        }
    }
    return dp[i][j1][j2] = ans;
}

int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> grid(r,vector<int>(c));
    // initalizing dp
    vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int> (c,-1)));
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        cin>>grid[i][j];
    }
    cout<<f(0,0,c-1,r,c,grid,dp)<<'\n';
    return 0;
}