/*
	- Should Consider the Number of squars as the piles 
	- For each stone in square X it's a pile with X stone 
	- Xor the their grundy number which is thier size ( square index )
	- Check if X!=0

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
        for(int i=1;i<=n;i++)
        {
            cin>>tmp;
            while(tmp--)
                x^=i;
        }
        if(x)
            cout<<"Tom Wins"<<endl;
        else
            cout<<"Hanks Wins"<<endl;
    }

}
