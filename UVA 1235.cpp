/*

    - Build MST if two keys in the same group one can easily jump to another
    - sort the distance between all keys and check if they are on the team or not
    - If not add merge the teams and sum the edge value

*/


#include<bits/stdc++.h>

using namespace std;

int calc(string a,string b)
{
    int cnt=0;
    for(int i=0; i<a.size(); i++)
    {
        if(b[i]>=a[i])
            cnt+=min((b[i]-'0')-(a[i]-'0'),((9-(b[i]-'0'))+(a[i]-'0'))+1);
        else
            cnt+=min((a[i]-'0')-(b[i]-'0'),((9-(a[i]-'0'))+(b[i]-'0'))+1);
    }
    return cnt;
}

struct mst
{
public:
    int par[505];
    int cnt[505];
    mst()
    {
        for(int i=0; i<505; i++)
            par[i]=i;
        for(int i=0; i<505; i++)
            cnt[i]=1;
    }
    int getpar(int root)
    {
        if(par[root]==root)
            return root;
        return par[root]=getpar(par[root]);
    }
    void mer(int x,int y)
    {
        if(cnt[x]>cnt[y])
            swap(x,y);
        par[getpar(x)]=getpar(y);
        cnt[y]+=cnt[x];
    }
    bool same(int x,int y)
    {
        return getpar(x)==getpar(y);
    }
};

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        string arr[n+1];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        arr[n]="0000";
        vector<pair<int,pair<int,int> > >ed;
        for(int i=0; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                if(i!=j)
                    ed.push_back({calc(arr[i],arr[j]),{i,j}});
        mst d;
        sort(ed.begin(),ed.end());
        int ans=0;
        bool check=0;
        for(int i=0; i<ed.size(); i++)
        {
            if(d.same(ed[i].second.first,ed[i].second.second))
                continue;
            if(check && (ed[i].second.second==n ||ed[i].second.first==n))
                continue;
            if(ed[i].second.first==n || ed[i].second.second==n)
                check=1;
            //cout<<ed[i].first<<" "<<arr[ed[i].second.first]<<" "<<arr[ed[i].second.second]<<endl;
            ans+=ed[i].first;
            d.mer(ed[i].second.first,ed[i].second.second);
        }
        cout<<ans<<endl;
    }
}
