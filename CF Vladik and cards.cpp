#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e3+5;
vector<int> v[8];
int n;
vector<int>::iterator it;
int dp[N][1<<8],arr[N],pos[N];

int solve(int ind,int msk,int x)
{
    if(ind==n)
    {
        if(msk==((1<<8)-1))
            return 0;
        return INT_MIN;
    }
    if(dp[ind][msk]!=-1)
        return dp[ind][msk];
    int ans=INT_MIN;
    ans=max(ans,solve(ind+1,msk,x));
    if(!(msk&(1<<arr[ind]))){
    if(pos[ind]+x<v[arr[ind]].size()+1)
        ans=max(ans,x+solve(v[arr[ind]][pos[ind]+(x-1)]+1,msk|(1<<arr[ind]),x));
    if(pos[ind]+x<v[arr[ind]].size())
        ans=max(ans,x+1+solve(v[arr[ind]][pos[ind]+x]+1,msk|(1<<arr[ind]),x));
    }
    return dp[ind][msk]=ans;
}

bool check(int x)
{
    memset(dp,-1,sizeof(dp));
    return (solve(0,0,x)>=0);
}

int bs(int low,int high,int req)
{
    if(low>high)
        return req;
    int mid=(low+high)/2;
    if(check(mid))
        return bs(mid+1,high,mid);
    return bs(low,mid-1,req);
}

int main()
{
    cin>>n;
    set<int>s;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        s.insert(arr[i]);
        v[--arr[i]].push_back(i);
        pos[i]=v[arr[i]].size()-1;
    }
    int t=bs(1,N,1);
    memset(dp,-1,sizeof(dp));
    cout<<max((int)s.size(),solve(0,0,t));
    return 0;
}