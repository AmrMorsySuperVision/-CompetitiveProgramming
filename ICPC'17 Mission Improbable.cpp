#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct MaximumMatching
{
    vector<int> m1, m2, seen;
    vector<vector<int> > g;
    int seen_id;
    MaximumMatching(int numNodesLeft, int numNodesRight)
    {
        g = vector<vector<int> >(numNodesLeft, vector<int>());
        m1 = vector<int>(numNodesLeft, -1);
        m2 = vector<int>(numNodesRight, -1);
        seen_id = 0;
        seen = vector<int>(numNodesRight, 0);
    }
    void addEdge(int leftNode, int rightNode)
    {
        assert(leftNode < int(m1.size()));
        assert(rightNode < int(m2.size()));
        g[leftNode].push_back(rightNode);
    }
    int getMaxMatching()
    {
        int ans = 0;
        for (int node = 0; node < int(m1.size()); node++)
        {
            seen_id++;
            if (dfs(node)) ans++;
        }
        return ans;
    }
    bool dfs(int node)
    {
        for (int i = 0; i < int(g[node].size()); i++)
        {
            int child = g[node][i];
            // if the child is not matched yet, match it with me
            if (m2[child] == -1)
            {
                m2[child] = node;
                m1[node] = child;
                return true;
            }

            // if the child was seen before (some other node tried to take it), leave it
            if (seen[child] == seen_id) continue;
            seen[child] = seen_id;

            // if the child is already matched with some other node, try to match that other node is some other way
            int enemy = m2[child];
            // take the child for me
            m1[enemy] = -1;
            m1[node] = child;
            m2[child] = node;
            // try to match the enemy
            if (dfs(enemy)) return true;
            // match the child with the enemy if not successful
            m1[enemy] = child;
            m1[node] = -1;
            m2[child] = enemy;
        }
        return  false;
    }

};

int row[105],col[105],arr[105][105];
bool visr[105],visc[105];
int main()
{
    int r,c;
    cin>>r>>c;

    ll ans=0;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>arr[i][j];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            ans+=max(0,arr[i][j]-1);
            row[i]=max(row[i],arr[i][j]);
            col[j]=max(col[j],arr[i][j]);
        }
    MaximumMatching M(105,105);
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(row[i]==col[j] && arr[i][j])
                M.addEdge(i,j);
    M.getMaxMatching();
    /* for(int i=0; i<M.g.size(); i++)
     {
         if(M.g[i].size())
             cout<<i<<" : ";
         for(int j=0; j<M.g[i].size(); j++)
             cout<<M.g[i][j]<<" ";
         if(M.g[i].size())
             cout<<endl;
     }*/
    for(int i=0; i<M.m1.size(); i++)
    {
        if(M.m1[i]==-1)
            continue;
        visr[i]=1;
        visc[M.m1[i]]=1;
        ans-=max(0,col[M.m1[i]]-1);
    }
    for(int i=0; i<r; i++)
        if(!visr[i])
            ans-=max(0,row[i]-1);
    for(int i=0; i<c; i++)
        if(!visc[i])
            ans-=max(0,col[i]-1);
    cout<<ans<<endl;
    return 0;
}
