/*
	- Do BS on the maximum flow for each bear then divid the edge by mid
	- If max flow >= X then it's valid case else dec the flow
*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 2000000000;

struct Edge
{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) { }
};

struct Dinic
{
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) { }

    void AddEdge(int from, int to, int cap)
    {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if(from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t)
    {
        fill(dad.begin(), dad.end(), (Edge *)NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while(head < tail)
        {
            int x = Q[head++];
            for(int i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if(!dad[e.to] && e.cap - e.flow > 0)
                {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if(!dad[t]) return 0;

        long long totflow = 0;
        for(int i = 0; i < G[t].size(); i++)
        {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                if(!e)
                {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if(amt == 0) continue;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t)
    {
        long long totflow = 0;
        while(long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

const int N=55;
int n,m,x;
vector<pair<int,double> > tree[N];

int main()
{
    cin>>n>>m>>x;
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        tree[a].push_back({b,c});
    }
    double low=0,high=1e9,mid,req=0;
    for(int k=0;k<400;k++)
    {
        mid=(low+high)/2;
        Dinic d(n+1);
        for(int i=1;i<=n;i++)
            for(int j=0;j<tree[i].size();j++)
                d.AddEdge(i,tree[i][j].first,floor(tree[i][j].second/mid));
        if(d.GetMaxFlow(1,n)>=x)
            low=mid;
        else
            high=mid;
    }
    cout<<fixed<<setprecision(8)<<max(1.0,mid*x)<<endl;
    return 0;
}