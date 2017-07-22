#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e3+5;
int dp[N][N][2];
int arr[N];
int n,m;

bool solve(int ind,int sum,bool c)
{
    if(ind==n)
        return ((!(sum%m))&&c);
    if(dp[ind][sum][c]!=-1)
        return dp[ind][sum][c];
    bool check=0;
    check|=solve(ind+1,(sum+arr[ind])%m,1);
    check|=solve(ind+1,sum,c);
    return dp[ind][sum][c]=check;
}

int main()
{
    cin>>n>>m;
    if(n>m)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
        cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    if(solve(0,0,0))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}