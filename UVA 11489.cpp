/*
	- The Greedy startgey whenever there's a move take it

*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	int t;
	cin>>t;
	int k=1;
	while(t--)
	{
		string s;
		cin>>s;
		int sum=0;
		for(int i=0;i<s.size();i++)
			sum+=s[i]-'0';
		bool check=1,t=0;
		while(!t){
			t=1;
			for(int i=0;i<s.size();i++){
				if(s[i]=='.')
					continue;
				if((sum-(s[i]-'0'))%3==0)
				{
					t=0;
					sum-=(s[i]-'0');
					s[i]='.';
					check=!check;
				}
			}
		}
		cout<<"Case "<<k++<<": ";
		if(!check)
			cout<<"S"<<endl;
		else
			cout<<"T"<<endl;
	}
}
