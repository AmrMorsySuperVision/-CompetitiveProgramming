#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class NetworkXMessageRecovery
{
public:
    string recover(vector <string> messages)
    {
        set<char> have;
        map<char,vector<char> > mp;
        map<char,bool> check;
        for(int i=0; i<messages.size(); i++)
            for(int j=0; j<messages[i].size(); j++)
            {
                have.insert(messages[i][j]);
                for(int k=0; k<j; k++)
                    mp[messages[i][j]].push_back(messages[i][k]);
            }
        string ans="";
        while(!have.empty())
        {
            set<char>::iterator it;
            set<char> can;
            for(it=have.begin(); it!=have.end(); it++){
                char c=(*it);
                bool f=1;
                for(int i=0; i<mp[c].size(); i++)
                    if(!check[mp[c][i]])
                        f=0;
                if(f)
                    can.insert(c);
            }
            for(it=can.begin();it!=can.end();it++)
            {
                check[(*it)]=1;
                ans+=(*it);
                have.erase((*it));
                break;
            }
        }
        return ans;
    }
};