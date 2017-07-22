#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int m,d;
int const N=2e3+5;
int dp[N][N][2][2];
string a,b;
ll mod=1e9+7;

ll solve(int ind,int val,bool G,bool L)
{
    if(ind==a.size())
        return !val;
    if(dp[ind][val][G][L]!=-1)
       return dp[ind][val][G][L];
    int st=a[ind]-'0',en=b[ind]-'0';
    int aa=st,bb=en;
    if(G)
        st=0;
    if(L)
        en=9;
    ll ans=0;
    if(ind%2)
    {
        if(d<st || d>en)
            return dp[ind][val][G][L]=0;
        ans=(ans+solve(ind+1,((val*10)+d)%m,G|(d>aa),L|(d<bb)))%mod;
    }
    else
    {
        for(int i=st; i<=en; i++)
        {
            if(i!=d || ind%2)
                ans=(ans+solve(ind+1,((val*10)+i)%m,G|(i>aa),L|(i<bb)))%mod;
        }
    }
    return dp[ind][val][G][L]=ans;
}

int main()
{
    cin>>m>>d;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0,0)<<endl;
    return 0;
}