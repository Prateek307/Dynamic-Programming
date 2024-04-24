// link to the problem ---> https://www.naukri.com/code360/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std;


void solve(int i ,int target,vector<int>&v , vector<int>&ans, set<vector<int>>&st)
{

    if(target==0)
    {
        sort(ans.begin(),ans.end());
        st.insert(ans);
        return;
    }

    if(i==v.size() || target<0)
    {
        return;
    }

    ans.push_back(v[i]);
    solve(i,target-v[i],v,ans,st);
    ans.pop_back();
    solve(i+1,target,v,ans,st);
}

int main()
{ 
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(auto &it : v)
    cin>>it;
    vector<int> ans;
    set<vector<int>> st;
    solve(0,target,v,ans,st);
    cout<<st.size()<<'\n';
    return 0;
}