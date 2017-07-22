#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=3e4+5;

int arr[N];
int dp[N][2005];
int n,d,x;

int solve(int ind,int l)
{
    if(ind>30000)
        return 0;
    int x=l-d;
    x+=1000;
    if(dp[ind][x]!=-1)
        return dp[ind][x];
    int ans=0;
    ans=max(ans,arr[ind]+solve(ind+l,l));
    ans=max(ans,arr[ind]+solve(ind+l+1,l+1));
    if(l>1)
        ans=max(ans,arr[ind]+solve(ind+l-1,l-1));
    return dp[ind][x]=ans;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        arr[x]++;
    }
    memset(dp,-1,sizeof dp);
    cout<<solve(d,d)<<endl;
    return 0;
}