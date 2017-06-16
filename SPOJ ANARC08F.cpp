#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int f[101][101];
map<string,int> mp;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,q,m,g=1;
    while(cin>>n>>q>>m)
    {
        if(!n && !m && !q)
            break;
        mp.clear();
        string base,arr[q];
        cin>>base;
        for(int i=0; i<q; i++)
            cin>>arr[i];
        char x,y,k,l;
        string a,b;
        int w,cnt=1;
        mp[base]=cnt;
        for(int i=0; i<=100; i++)
            for(int j=0; j<=100; j++)
                f[i][j]=1e8;
        for(int i=0; i<=100; i++)
            f[i][i]=0;
        for(int i=0; i<m; i++)
        {
            cin>>a>>x>>y>>w>>k>>l>>b;
            if(!mp[a])
                mp[a]=++cnt;
            if(!mp[b])
                mp[b]=++cnt;
            if(x=='<')
                f[mp[b]][mp[a]]=min(f[mp[b]][mp[a]],w);
            if(l=='>')
                f[mp[a]][mp[b]]=min(f[mp[a]][mp[b]],w);
        }
        for(int k=0; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        ll ans=0;
        for(int i=0; i<q; i++)
        {
            ans+=f[mp[base]][mp[arr[i]]];
            ans+=f[mp[arr[i]]][mp[base]];
        }
        cout<<g++<<". "<<ans<<endl;
    }


    return 0;
}
