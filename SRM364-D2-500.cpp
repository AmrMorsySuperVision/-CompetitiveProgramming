/*
	- Parsed the string
	- Maped each player and each player score and each team score
	- Sorted the answer

*/


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


class Paintball
{
public:
    vector <string> getLeaderboard(vector <string> players, vector <string> messages)
    {
        map<string,int> score,mp;
        map<string,string> team;
        for(int i=0; i<players.size(); i++)
        {
            string a,b;
            bool check=0;
            for(int j=0; j<players[i].size(); j++)
            {
                if(players[i][j]==' ')
                {
                    check=1;
                    continue;
                }
                if(!check)
                    a+=players[i][j];
                else
                    b+=players[i][j];
            }
            score[b]=0;
            mp[a]=0;
            team[a]=b;
        }
        for(int i=0; i<messages.size(); i++)
        {
            int cnt=0;
            string a,b;
            for(int j=0; j<messages[i].size(); j++)
            {
                if(messages[i][j]==' ')
                {
                    cnt++;
                    continue;
                }
                if(!cnt)
                    a+=messages[i][j];
                else if(cnt==2)
                    b+=messages[i][j];
            }
            if(team[a]!=team[b])
            {
                score[team[a]]++;
                score[team[b]]--;
                mp[a]++;
                mp[b]--;
            }
            else
            {
                score[team[a]]--;
                mp[a]--;
            }
        }
        vector<pair<int,string> > arr;
        map<string,int>::iterator it;
        for(it=score.begin(); it!=score.end(); it++)
            arr.push_back({it->second,it->first});
        for(int i=0; i<arr.size(); i++)
            for(int j=i+1; j<arr.size(); j++)
                if(arr[j].first>arr[i].first)
                    swap(arr[i],arr[j]);
                else if(arr[j].first == arr[i].first && arr[j].second<arr[i].second)
                    swap(arr[i],arr[j]);
        vector<string> v;
        for(int i=0; i<arr.size(); i++)
        {
            string tmp="";
            tmp+=arr[i].second;
            stringstream ss;
            ss<<arr[i].first;
            string t;
            ss>>t;
            tmp+=' ';
            tmp+=t;
            v.push_back(tmp);
            vector<pair<int,string> > brr;
            for(it=mp.begin(); it!=mp.end(); it++)
            {
                if(team[it->first]==arr[i].second)
                    brr.push_back({mp[it->first],it->first});
            }
            for(int j=0;j<brr.size();j++)
                for(int k=j+1;k<brr.size();k++)
                    if(brr[k].first>brr[j].first)
                        swap(brr[k],brr[j]);
                    else if(brr[k].first==brr[j].first && brr[k].second<brr[j].second)
                        swap(brr[k],brr[j]);
            for(int j=0;j<brr.size();j++)
            {
                string tmp2="  ";
                tmp2+=brr[j].second;
                tmp2+=' ';
                stringstream tt;
                tt<<brr[j].first;
                string t2;
                tt>>t2;
                tmp2+=t2;
                v.push_back(tmp2);
            }
        }
        return v;
    }
};