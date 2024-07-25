// link to the problem ---> https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int solve(int n , vector<int>&dp)
    {
        if(n==0)
        return 0;
        
        if(dp[n]!=-1)
        return dp[n];
        
        int i,temp,ans = n;
        for(i=1;i*i<=n;i++)
        {
            temp = i*i;
            ans = min(ans,1 + solve(n-temp,dp));
        }
        return dp[n] = ans;
    }
  
    int MinSquares(int n) {
        // Code here
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends