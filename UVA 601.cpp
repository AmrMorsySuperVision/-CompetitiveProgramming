#include<bits/stdc++.h>

using namespace std;

char arr[90][90];
bool vis[90][90];
bool vis2[90][90][2];
int x[]= {0,0,1,-1};
int y[]= {1,-1,0,0};
int n;
bool dfs(int i,int j)
{
    if(j==n)
        return 1;
    if(vis[i][j])
        return 0;
    vis[i][j]=1;
    bool check=0;
    for(int k=0; k<4; k++)
        if(arr[i+x[k]][j+y[k]]=='W')
            check|=dfs(i+x[k],j+y[k]);
    return check;
}

bool dfs2(int i,int j)
{
    if(i==n)
        return 1;
    if(vis[i][j])
        return 0;
    vis[i][j]=1;
    bool check=0;
    for(int k=0; k<4; k++)
        if(arr[i+x[k]][j+y[k]]=='B')
            check|=dfs2(i+x[k],j+y[k]);
    return check;
}

bool dfs3(int i,int j,bool d)
{
    if(j==n)
        return 1;
    if(vis2[i][j][d])
        return 0;
    vis2[i][j][d]=1;
    bool check=0;
    for(int k=0; k<4; k++)
        if(arr[i+x[k]][j+y[k]]=='W')
            check|=dfs3(i+x[k],j+y[k],d);
        else if(arr[i+x[k]][j+y[k]]=='U' && d==0)
            check|=dfs3(i+x[k],j+y[k],1);
    return check;
}

bool dfs4(int i,int j,bool d)
{
    if(i==n)
        return 1;
    if(vis2[i][j][d])
        return 0;
    vis2[i][j][d]=1;
    bool check=0;
    for(int k=0; k<4; k++)
        if(arr[i+x[k]][j+y[k]]=='B')
            check|=dfs4(i+x[k],j+y[k],d);
        else if(arr[i+x[k]][j+y[k]]=='U' && d==0)
            check|=dfs4(i+x[k],j+y[k],1);
    return check;
}


int main()
{
    while(cin>>n)
    {
        if(!n)
            break;
        memset(arr,'.',sizeof(arr));
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                cin>>arr[i][j];
        bool check=0;
        for(int i=1; i<=n; i++)
            if(arr[i][1]=='W')
                check|=dfs(i,1);
        if(check)
        {
            cout<<"White has a winning path."<<endl;
            continue;
        }
        check=0;
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
            if(arr[1][i]=='B')
                check|=dfs2(1,i);
        if(check)
        {
            cout<<"Black has a winning path."<<endl;
            continue;
        }
        check=0;
        memset(vis2,0,sizeof(vis2));
        for(int i=1; i<=n; i++)
            if(arr[i][1]=='W')
                check|=dfs3(i,1,0);
            else if(arr[i][1]=='U')
                check|=dfs3(i,1,1);
        if(check)
        {
            cout<<"White can win in one move."<<endl;
            continue;
        }
        check=0;
        memset(vis2,0,sizeof(vis2));
        for(int i=1; i<=n; i++)
            if(arr[1][i]=='B')
                check|=dfs4(1,i,0);
            else if(arr[1][i]=='U')
                check|=dfs4(1,i,1);
        if(check)
        {
            cout<<"Black can win in one move."<<endl;
            continue;
        }
        cout<<"There is no winning path."<<endl;
    }
    return 0;
}