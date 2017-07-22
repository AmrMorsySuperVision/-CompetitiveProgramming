#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e5+5;
vector<int> tree[N];
int par[N];
pair<int,int> e[N];
map<pair<int,int>,int> mp;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        e[i]= {u,v};
        mp[e[i]]=i;
        tree[u].push_back(v);
        par[v]++;
    }
    queue<int> q;
    int ans=0;
    for(int i=1; i<=n; i++)
        if(!par[i])
            q.push(i);
    vector<int> arr;
    while(q.size())
    {
        if(q.size()>1)
        {
            cout<<-1<<endl;
            return 0;
        }
        int root=q.front();
        q.pop();
        arr.push_back(root);
        for(int i=0; i<tree[root].size(); i++)
        {
            par[tree[root][i]]--;
            if(!par[tree[root][i]])
                q.push(tree[root][i]);
        }
    }
    for(int i=0; i<arr.size()-1; i++)
        ans=max(ans,mp[ {arr[i],arr[i+1]}]);
    cout<<ans+1<<endl;
    return 0;
}