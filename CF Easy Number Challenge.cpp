#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool se[1000001];

void sieve()
{
    se[0]=0;
    se[1]=1;
    for(int i=2; i*i<=1000000; i++)
    {
        if(se[i]==0)
            for(int j=i*i; j<=1000000; j+=i)
                se[j]=1;
    }
}

ll re(ll x)
{
    ll y=1;
    for(ll i=2; i<=x; i++)
    {
        ll e=0;
        while(x%i==0)
        {
            x/=i;
            e++;
        }
        y*=(e+1);
    }
    return y;
}

int main()
{
    sieve();
    int a,b,c;
    cin>>a>>b>>c;
    ll ans=0;
    for(int i=1; i<=a; i++)
    {
        for(int j=1; j<=b; j++)
        {
            for(int k=1; k<=c; k++)
            {
                if(!se[i*j*k])
                    ans+=2;
                else
                    ans+=re(i*j*k);
                ans%=1073741824;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}