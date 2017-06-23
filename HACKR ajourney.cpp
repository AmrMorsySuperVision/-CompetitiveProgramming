/*

    - For the last K digits : Normal fast power with mod
    - For the first K digits : break the number into 10^x and 10^0.y where y is the first digits of the number 
    - Multiply y by 10^k to get the first K digits

*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,k,mod;

ll fp(ll a,ll b)
{
    if(!b)
        return 1;
    if(b%2)
        return (fp((a*a)%mod,b/2)*a)%mod;
    return fp((a*a)%mod,b/2)%mod;
}

ll firstk(ll n,ll k)
{
    long double p=n*log10((long double)2);
    long double d=p-ll(p);
    d=pow(10,d);
    ll num=pow(10,k-1)*d;
    return num;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        mod=1;
        for(int i=0;i<k;i++)
            mod*=10;
        ll last=fp(2,n-1);
        ll first=firstk(n-1,k);
        cout<<first+last<<endl;
    }
    return 0;
}
