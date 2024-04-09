#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n==1)
    return 1;
    if(n==0)
    return 0;

    int prev = 1 , prev2 = 0 , curr;
    for(int i=2;i<=n;i++)
    {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{ 
    int n;
    cin>>n;
    cout<<fib(n)<<'\n';
    return 0;
}