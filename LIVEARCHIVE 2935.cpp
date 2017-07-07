/*
	- Using a tree property that there's a unique path between each 2 nodes
	- For each subtree find the string the represt it after that recall the function to find the smallest string in the current sub tree

*/


#include<bits/stdc++.h>

using namespace std;

string re(string a)
{
    if(a.size()==0)
        return "";
    string tmp="";
    vector<string> v;
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
        tmp+=a[i];
        if(a[i]=='0')
            cnt++;
        else
            cnt--;
        if(!cnt)
        {
            tmp=tmp.substr(1,tmp.size()-2);
            v.push_back("0"+re(tmp)+"1");
            tmp="";
        }
    }
    sort(v.begin(),v.end());
    tmp="";
    for(int i=0;i<v.size();i++)
        tmp+=v[i];
    return tmp;
}


int main()
{
    int tc;
    cin>>tc;
    string a,b;
    while(tc--)
    {
        cin>>a>>b;
        //cout<<re(a)<<endl<<re(b)<<endl;
        if(re(a)==re(b))
            cout<<"same"<<endl;
        else
            cout<<"different"<<endl;
    }
    return 0;
}
