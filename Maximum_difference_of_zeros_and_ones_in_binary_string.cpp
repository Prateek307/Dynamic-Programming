// link to the problem ---> https://www.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int maxSubstring(string S)
    {
        // Your code goes here
        int ones = 0, zeros = 0;
        int i, ans = 0;
        for (i = 0; i < S.size(); i++)
        {
            if (S[i] == '0')
            {
                zeros++;
            }
            else
            {
                zeros--;
                ones++;
            }
            zeros = max(zeros, 0);
            ans = max(ans, zeros);
        }
        if (ones == S.size())
            return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.maxSubstring(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends