/*
	Idea: 
		- run dijkstra to find the shortest path between the start and the end nodes
        - if path found print it if not use the direct free path
*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<char> tree[((int)'Z')+5];
        map<pair<char,char>,int> cost;
        for(int i=0;i<m;i++)
        {
            char u,v;int x;
            cin>>u>>v>>x;
            tree[u].push_back(v);
            tree[v].push_back(u);
            cost[{u,v}]=x;
            cost[{v,u}]=x;
        }
        int q;
        cin>>q;
        while(q--)
        {
            char a,b;
            cin>>a>>b;
            set<pair<int,pair<char,char> > > se;
            pair<int,pair<char,char> >tmp;
            bool vis[((int)'Z')+5]={0};
            int par[((int)'Z')+5];
            memset(par,-1,sizeof(par));
            se.insert({0,{a,0}});
            while(se.size())
            {
                tmp=(*se.begin());
                se.erase(se.begin());
                if(vis[tmp.second.first])
                    continue;
                vis[tmp.second.first]=1;
                par[tmp.second.first]=tmp.second.second;
                for(int i=0;i<tree[tmp.second.first].size();i++)
                se.insert({tmp.first+cost[{tree[tmp.second.first][i],tmp.second.first}],{tree[tmp.second.first][i],tmp.second.first}});
            }
            if(par[b]==-1)
                cout<<a<<" "<<b<<endl;
            else
            {
                vector<char> ans;
                while(par[b]!=-1)
                {
                    ans.push_back(b);
                    b=par[b];
                }
                for(int i=ans.size()-1;i>=0;i--)
                {
                    cout<<ans[i];
                    if(i)
                        cout<<" ";
                }
                cout<<endl;
            }
        }
    }
}
