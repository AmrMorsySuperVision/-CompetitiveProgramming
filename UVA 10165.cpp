/*

	- Get the grundy number of each nim which is it's size since they can take any number of stones
	- Xor the numbers and check if x!=0

*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	while(cin>>n)
    {
        if(!n)
            break;
        int x=0,tmp;
        while(n--)
        {
            cin>>tmp;
            x^=tmp;
        }
        if(x)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

}
