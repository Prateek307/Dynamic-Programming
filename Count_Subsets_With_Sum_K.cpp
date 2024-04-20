// link to the problem ---> https://www.naukri.com/code360/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos

const long long mod = 1e9 + 7;
using ll = long long;
ll solve(ll i, ll target, vector<int> &v, vector<vector<int>> &dp)
{

    if (target == 0) // If the target is achieved, return 1 way
        return 1;

    if (i == v.size() || target < 0) // If index exceeds array size or target becomes negative, return 0 ways
    {
        return 0;
    }

    if (dp[i][target] != -1)
        return dp[i][target];

    // Calculate the number of ways by either including or excluding the current element
    int take = 0, dontTake;
    if (v[i] <= target)
        take = solve(i + 1, target - v[i], v, dp) % mod;
    dontTake = solve(i + 1, target, v, dp) % mod;

    return dp[i][target] = (take + dontTake) % mod;
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    // Dynamically allocate memory for dp based on actual target values
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return (int)solve(0, k, arr, dp);
}
