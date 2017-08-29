/*
	- Normal Nim game with a corner case if all piles = 1

*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
    {
        int n;
        cin>>n;
        int x=0,tmp;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cin>>tmp;
            if(tmp==1)
                cnt++;
            x^=tmp;
        }
        if(cnt==n)
        {
            if(n%2==0)
                cout<<"John"<<endl;
            else
                cout<<"Brother"<<endl;
            continue;
        }
        if(x)
            cout<<"John"<<endl;
        else
            cout<<"Brother"<<endl;
    }

}

}
