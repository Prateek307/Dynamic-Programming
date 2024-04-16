// link to the problem ---> https://leetcode.com/problems/partition-equal-subset-sum/description/

#include <vector>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        // If the total sum is odd, it's not possible to partition the array into two subsets with equal sums.
        if (totalSum % 2 != 0)
            return false;

        int targetSum = totalSum / 2;
        int n = nums.size();

        // Initialize a 2D DP table with dimensions (n+1) x (targetSum+1).
        vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

        // Base case: It's always possible to achieve a sum of 0 by not selecting any element.
        for (int i = 0; i <= n; ++i)
            dp[i][0] = true;

        // Fill the DP table iteratively.
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= targetSum; ++j)
            {
                // If the current element is greater than the current sum j, it cannot be included.
                if (nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                {
                    // Otherwise, we have two options: include the current element or exclude it.
                    // If either option leads to a true result, set dp[i][j] to true.
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        // The result is stored in dp[n][targetSum].
        return dp[n][targetSum];
    }
};
