/*
	- We need to check all possible moves to the current state and calculate it's grundy number
	- Putting the grundy number in an array we the problem became we have array wa need to get the value of Xor from range [l,r] with update
	- Using segnment tree to get the answer of the query

*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e5+5;
int a[N];
int st[5*N];

void build(int low,int high,int pos)
{
    if(low==high)
    {
        st[pos]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(mid+1,high,2*pos+2);
    build(low,mid,2*pos+1);
    st[pos]=st[2*pos+1]^st[2*pos+2];
}

int get(int l,int r,int low,int high,int pos)
{
    if(low>r || high<l)
        return 0;
    if(low>=l && high<=r)
        return st[pos];
    int mid=(low+high)/2;
    return get(l,r,mid+1,high,2*pos+2)^get(l,r,low,mid,2*pos+1);
}

void update(int l,int r,int low,int high,int pos,int d)
{
    if(low>r || high<l)
        return;
    if(low==high)
    {
        a[low]=d;
        st[pos]=d;
        return;
    }
    int mid=(low+high)/2;
    update(l,r,mid+1,high,2*pos+2,d);
    update(l,r,low,mid,2*pos+1,d);
    st[pos]=st[2*pos+1]^st[2*pos+2];
}

bool check(vector<string> tmp)
{
    for(int i=0; i<3; i++)
        if(tmp[i]!=tmp[i+1])
            return 0;
    if(tmp[0]=="0000")
        return 1;
    return 0;
}
bool check(int i,int j,int l,int m,vector<string> tmp)
{
    for(int a=i; a<=l; a++)
        for(int b=j; b<=m; b++)
            if(tmp[a][b]!='1')
                return 0;
    return 1;
}
vector<string> trans(int i,int j,int l,int m,vector<string> tmp)
{
    for(int a=i; a<=l; a++)
        for(int b=j; b<=m; b++)
            tmp[a][b]='0';
    return tmp;
}
map<vector<string>,int> dp,vis;
int mex(vector<string> tmp)
{
    set<int> se;
    if(vis[tmp])
          return dp[tmp];
    if(check(tmp))
        return 0;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            for(int s=i; s<4; s++)
                for(int e=j; e<4; e++)
                    if(check(i,j,s,e,tmp))
                        se.insert(mex(trans(i,j,s,e,tmp)));
    int cnt=0;
    set<int>::iterator it;
    for(it=se.begin(); it!=se.end(); it++)
    {
        if((*it)!=cnt)
            break;
        cnt++;
    }
    vis[tmp]=1;
    return dp[tmp]=cnt;
}

vector<vector<string> > arr;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--)
    {
        arr.clear();
        vector<string> tmp;
        string s;
        int n,q;
        cin>>n>>q;
        for(int i=0; i<n; i++)
        {
            tmp.clear();
            for(int j=0; j<4; j++)
            {
                cin>>s;
                tmp.push_back(s);
            }
            arr.push_back(tmp);
        }
        int x=0;
        for(int i=0; i<arr.size(); i++)
            a[i]=mex(arr[i]);
        build(0,n-1,0);
        int t,l,r,ind;
        while(q--)
        {
            cin>>t;
            if(t==1)
            {
                cin>>l>>r;
                l--;
                r--;
                x=get(l,r,0,n-1,0);
                if(x)
                    cout<<"Pishty"<<endl;
                else
                    cout<<"Lotsy"<<endl;
            }
            else
            {
                cin>>ind;
                ind--;
                tmp.clear();
                for(int j=0; j<4; j++)
                {
                    cin>>s;
                    tmp.push_back(s);
                }
                update(ind,ind,0,n-1,0,mex(tmp));
            }
        }
    }
}
