/*

	- First we need to find the number of numbers that starts with 1 [ 10^i , 2*(10^i) -1]
	- After that run a simple dp that calculate the probability that at index i I have J good strings 

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fp(ll a,ll b)
{
    if(!b)
        return 1;
    if(b%2)
        return fp(a*a,b/2)*a;
    return fp(a*a,b/2);
}

long double get(ll l,ll r)
{
    ll a,b;
    ll cnt=0;
    for(ll i=0;i<=18;i++)
    {
        a=fp(10,i);
        b=2*a-1;
        if(a>=l && b<=r)
            cnt+=(b-a)+1;
        else if(a<=l && b>=l)
            cnt+=(min(r,b)-l)+1;
       else if(a<=r && b>=r)
            cnt+=(r-max(a,l))+1;
    }
    return max(0ll,cnt);
}

const int N=1e3+5;
long double dp[N][N];
long double prob[N];

int main()
{
    long double n,k;
    cin>>n;
    long double a,b;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        prob[i]=get(a,b)/((b-a)+1.0);
    }
    cin>>k;
    dp[0][0]=1;
    prob[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
            dp[i][j]=prob[i]*dp[i-1][j-1]+((1.0-prob[i])*dp[i-1][j]);
    long double ans=0;
    for(long double i=0;i<=n;i++)
            if((i/n)*100.0>=k)
                ans+=dp[(int)n][(int)i];
        cout<<fixed<<setprecision(9)<<ans<<endl;
    return 0;
}