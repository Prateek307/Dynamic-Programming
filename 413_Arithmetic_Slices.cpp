// link to the problem ---> https://leetcode.com/problems/arithmetic-slices/

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &a)
    {
        int n = a.size();
        if (n < 3)
            return 0;

        int count = 0;
        int currLength = 0;

        for (int i = 2; i < n; i++)
        {
            if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
            {
                currLength++;
                count += currLength;
            }
            else
            {
                currLength = 0;
            }
        }

        return count;
    }
};