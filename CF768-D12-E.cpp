/*
	- Made a dp function to check the grundy pattern of one pile
	- Xor Grundy number and check the state
	
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
/*
int mex(int x,set<int> tmp)
{
    if(x==0)
        return 0;
    set<int>::iterator it;
    set<int>se;
    for(int i=1;i<=x;i++)
    {
        if(tmp.find(i)==tmp.end())
        {
            tmp.insert(i);
            se.insert(mex(x-i,tmp));
            tmp.erase(i);
        }
    }
    int cnt=0;
    for(it=se.begin();it!=se.end();it++){
        if((*it)!=cnt)
            break;
        cnt++;
    }
    return cnt;
}
*/
int main()
{
    vector<int> v;
    v.push_back(0);
    int x=1;
    for(int i=2;i<=20;i++)
    {
        for(int j=0;j<i;j++)
            v.push_back(x);
        x++;
    }
    int n;
    cin>>n;
    int tmp,xr=0;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        xr^=v[tmp];
    }
    if(!xr)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
