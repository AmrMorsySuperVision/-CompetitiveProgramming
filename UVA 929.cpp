#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[1005][1005];
bool vis[1005][1005];
int f1[]={0,1,-1,0};
int f2[]={1,0,0,-1};
int n,m;

bool valid(int x,int y)
{
    if(x>=1 && y>=1 && x<=n && y<=m)
        return 1;
    return 0;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(vis,0,sizeof(vis));
        memset(arr,0,sizeof(arr));
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>arr[i][j];
        set<pair<int,pair<int,int> > > se;
        pair<int,pair<int,int> > tmp;
        se.insert({0,{1,1}});
        int x,y,c;
        while(se.size())
        {
            tmp=(*se.begin());
            se.erase(se.begin());
            x=tmp.second.first;
            y=tmp.second.second;
            c=tmp.first+arr[x][y];
            if(vis[x][y])
                continue;
            vis[x][y]=1;
            if(x==n && y==m)
            {
                cout<<c<<endl;
                break;
            }
            for(int i=0;i<4;i++)
            {
                if(valid(x+f1[i],y+f2[i]))
                    se.insert({c,{x+f1[i],y+f2[i]}});
            }
        }
    }
    return 0;
}
