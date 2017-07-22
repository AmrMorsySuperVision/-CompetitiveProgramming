#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=5e6+1;
bool se[N];
int cnt[N];

void sieve()
{
    for(int i=2; i<N; i++)
        if(!se[i])
            for(int j=i; j<N; j+=i)
            {
                se[j]=1;
                int tmp=j;
                int sum=0;
                while(!(tmp%i))
                    tmp/=i,sum++;
                cnt[j]+=sum;
            }
    for(int i=1;i<N;i++)
        cnt[i]+=cnt[i-1];
}

int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    int a,b;
    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cnt[a]-cnt[b]);
    }
    return 0;
}