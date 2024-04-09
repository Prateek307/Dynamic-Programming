/*
In this problem you are having stairs you have tell in how many minimum steps you can reach the last step also at one time 
you can either jump  1 or  2 steps
*/

#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;


int ways(int i,vector<int> &dp)
{
    if(i==0 || i==1)
    return dp[i] = 1;

    if(dp[i]!=-1)
    return dp[i];

    int right,left;
    right = ways(i-1,dp);
    left = ways(i-2,dp);

    return dp[i] = ((right%mod) + (left%mod))%mod;
}
int main()
{ 
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<ways(n,dp);
    return 0;
}