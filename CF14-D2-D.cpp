/*
    - First iterate over all edges 
    - removing and edge a < == > b will disconnect the subtree containing a and the subtree containing b
    - Get the diameter of each subtree and multiply them
    - Maximize the answer
*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=205;
vector<int> tree[N];
bool vis[N];
vector<pair<int,int> > edges;
int far,c;

void farest(int root,int Otherside,int cnt){
    if(vis[root])
        return;
    vis[root]=1;
    if(cnt>=c)
    {
        c=cnt;
        far=root;
    }
    for(int i=0;i<tree[root].size();i++)
    {
        if(tree[root][i]==Otherside)
            continue;
        farest(tree[root][i],Otherside,cnt+1);
    }
}

int getDiameter(int root,int Otherside){
    memset(vis,0,sizeof(vis));
    farest(root,Otherside,0);
    c=0;
    memset(vis,0,sizeof(vis));
    farest(far,Otherside,0);
    return c;
}


int main(){
    int n;
    scanf("%d",&n);
    int u,v;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
        edges.push_back({u,v});
    }
    int x,y,ans=0;
    for(int i=0;i<edges.size();i++)
    {
        far=0;c=0;
        x=getDiameter(edges[i].first,edges[i].second);
        far=0;c=0;
        y=getDiameter(edges[i].second,edges[i].first);
        ans=max(ans,x*y);
    }
    printf("%d\n",ans);
    return 0;
}
