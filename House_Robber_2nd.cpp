/*

Problem Statement

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police
*/

class Solution
{
public:
    int solve(vector<int> &nums, int i, int n, vector<int> &dp)
    {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int include, exclude;
        include = nums[i] + solve(nums, i + 2, n, dp);
        exclude = solve(nums, i + 1, n, dp);

        return dp[i] = max(include, exclude);
    }
    int rob(vector<int> &nums)
    {
        vector<int> first, second;
        if (nums.size() == 1)
            return nums[0];
        int i, n = nums.size();
        for (i = 0; i < n; i++)
        {
            if (i != n - 1)
                first.push_back(nums[i]);
            if (i != 0)
                second.push_back(nums[i]);
        }
        vector<int> dp1(first.size(), -1);
        vector<int> dp2(second.size(), -1);
        return max(solve(first, 0, first.size(), dp1), solve(second, 0, second.size(), dp2));
    }
};