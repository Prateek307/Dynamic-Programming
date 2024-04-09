/*
Problem Statement
Frog 1 but the extra condition here is that now you can make k jumps
*/

//--------------------------------------------------------------------------------------------
// recursive approach

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int> &v, int i, vector<int> &dp, int k) {
    if (i == 0)
        return 0;

    if (i == 1)
        return abs(v[0] - v[1]);

    if (dp[i] != -1)
        return dp[i];

    int ans = INT_MAX; // Initialize ans locally within solve function

    for (int jump = 1; jump <= k && i - jump >= 0; jump++)
        ans = min(ans, abs(v[i] - v[i - jump]) + solve(v, i - jump, dp, k));

    return dp[i] = ans;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    vector<int> dp(n + 1, -1);
    cout << solve(v, n - 1, dp, k) << '\n'; // Remove 'ans' from main function call
    return 0;
}

//--------------------------------------------------------------------------------------------

// iteravtive approach or bottom up apporach

// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// int solve(vector<int> &v, vector<int> &dp, int k, int n)
// {
//     dp[0] = 0;
//     dp[1] = abs(v[0]-v[1]);

//     int ans = INT_MAX;

//     for(int i = 2 ; i < n ; i++)
//     {
//         int ans = INT_MAX;
//         for (int jump = 1; jump <= k && i - jump >= 0; jump++)
//         {
//             ans = min(ans, abs(v[i] - v[i - jump]) + dp[i - jump]);
//             dp[i] = ans;
//         }   
//     }
//     return dp[n-1];

// }

// int main()
// {
//     int n;
//     cin >> n;
//     int k;
//     cin >> k;
//     vector<int> v(n);
//     for (auto &it : v)
//         cin >> it;
//     vector<int> dp(n + 1, -1);
//     cout << solve(v,dp, k,n) << '\n'; 
//     return 0;
// }


