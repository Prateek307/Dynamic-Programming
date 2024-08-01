// link to the problem ---> https://www.geeksforgeeks.org/problems/skip-the-work5752/1

//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int solve(int i, int n, int a[], int dp[])
    {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int include = a[i] + solve(i + 2, n, a, dp); // include a[i]
        int exclude = solve(i + 1, n, a, dp);        // exclude a[i]

        return dp[i] = max(include, exclude);
    }

    int minAmount(int A[], int N)
    {
        // code here.
        int dp[N + 1];
        for (int i = 0; i < N + 1; i++)
            dp[i] = -1;
        int totalSum = 0;
        for (int i = 0; i < N; i++)
            totalSum += A[i];
        return totalSum - solve(0, N, A, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.minAmount(arr, n) << endl;
    }
}
// } Driver Code Ends