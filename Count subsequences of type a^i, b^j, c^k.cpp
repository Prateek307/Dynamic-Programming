// link to the problem --->https://www.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck4425/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template

class Solution
{
public:
    // s : given string
    // return the expected answer
    int fun(string &s)
    {
        // code here
        int i;
        int a = 0, b = 0, c = 0, mod = 1e9 + 7;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
            {
                a = (2 * a % mod + 1) % mod;
            }
            else if (s[i] == 'b')
            {
                b = (2 * b % mod + a) % mod;
            }
            else
            {
                c = (2 * c % mod + b) % mod;
            }
        }
        return c % mod;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.fun(s) << endl;
    }
    return 0;
}
// } Driver Code Ends