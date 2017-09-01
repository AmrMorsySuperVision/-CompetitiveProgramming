/*
	- If N is even Marsel will copy Timur and win
	- If N is Odd we can reduce the problem to one log with size M
	- I there's a divisor for M that is M/d >= K that mean he can break the log into more than one log which can't be broken anymore
	- M contains primes factors P1,P2,P3,P4,P5 if we can take as many prime factor as we can as long as the remaining will for a number > K hence if one of the remaing were to remove the number will be less that K

*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	if(n%2==0){
		cout<<"Marsel"<<endl;
		return 0;
	}
	bool check=0;
	for(int i=1;i*i<=m;i++)
	{
		if(m%i!=0)
			continue;
		int piles=i;
		if(piles !=1 && m/piles>=k){
			check=1;
			break;
		}
		piles=m/i;
		if(piles != 1 && m/piles>=k){
			check=1;
			break;
		}
	}
	if(check)
		cout<<"Timur";
	else
		cout<<"Marsel";
}
