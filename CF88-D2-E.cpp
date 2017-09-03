/*
	- There are 4 cases in this problem let a = #0's and b = #1's 
	- if a > b the answer is 00
	- if b > a+1 the answer is 11
	- if a == b || a+1 == b the answer is 01 or 10 depending on the last char in the string
	- Count a,b,x ( number of  ? ) 
	- then iterate on x try to add it on the 1's and on the 0's and go to the check function to add the answer 

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

set<string> ans;
set<string>::iterator it;

string s;

void check(int a,int b)
{
    char en=s[s.size()-1];
    if(a==b)
    {
        if(en=='1')
            ans.insert("01");
        if(en=='0')
            ans.insert("10");
    }
    if(a+1==b)
    {
        if(en=='1')
            ans.insert("01");
        if(en=='0')
            ans.insert("10");
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>s;
    int a=0,b=0,x=0;
    for(int i=0; i<s.size(); i++)
        if(s[i]=='0')
            a++;
        else if(s[i]=='1')
            b++;
        else
            x++;
    if(a+x>b)
        ans.insert("00");
    if(b+x>a+1)
        ans.insert("11");
    for(int i=0;i<=x;i++)
    {
        if(i && s[s.size()-1]=='?')
        {
            int rem=i;
            rem--;
            s[s.size()-1]='1';
            check(a+rem,b+1);
            check(a,b+rem+1);
            s[s.size()-1]='0';
            check(a+rem+1,b);
            check(a+1,b+rem);
            s[s.size()-1]='?';
        }
        else{
        check(a+i,b);
        check(a,b+i);}
    }
    for(it=ans.begin(); it!=ans.end(); it++)
        cout<<(*it)<<endl;
    return 0;
}
