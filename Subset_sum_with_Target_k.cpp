// #include<bits/stdc++.h>
// using namespace std;

// int solve(int i, int target, vector<int> &v, vector<vector<int>> &dp) {

//     if(target==0)
//     return 1;

//     if(i==v.size()-1)
//     {
//         return (v[i]==target);
//     }

//     if (dp[i][target] != -1)
//         return dp[i][target];

//     bool do_not_pick = solve(i + 1, target, v, dp);
//     bool pick = false;

//     if(v[i]<=target)
//     pick = solve(i + 1, target - v[i], v, dp);

//     return dp[i][target] = (pick|do_not_pick);
// }

// int main() {
//     int n, target;
//     cin >> n >> target;

//     vector<int> v(n);
//     for (int i = 0; i < n; ++i)
//         cin >> v[i];

//     vector<vector<int>> dp(n, vector<int>(target+1, -1));
//     cout << solve(0, target, v, dp) << '\n';

//     return 0;
// }

// solving using the iterative approach

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Base case: If the sum is 0, then there's always an empty subset that sums up to 0.
    dp[0][0] = 1;

    // Base case: If the first element equals the target, then there's a subset with sum equal to target.
    if (v[0] <= target)
        dp[0][v[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            // Do not pick the current element
            dp[i][j] = dp[i - 1][j];
            // If current element can be included, update based on whether we pick it or not
            if (v[i] <= j)
                dp[i][j] |= dp[i - 1][j - v[i]];
        }
    }

    cout << (dp[n - 1][target] ? "1" : "0") << '\n';

    return 0;
}
