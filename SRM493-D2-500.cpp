/*
	- First sort the 2 arrays
	- Count the number of elements I have in map
	- For each element in the opposite array count if I have a number strictily larger than it
	- after counting sum the maximium X elements

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


class PlayGame {
public:
	int saveCreatures(vector <int> you, vector <int> computer) {
		map<int,int> mp;
		for(int i=0;i<you.size();i++)
            mp[you[i]]++;
        map<int,int>::iterator it;
        sort(computer.begin(),computer.end());
        sort(you.begin(),you.end());
        int cnt=0;
        for(int i=0;i<computer.size();i++)
        {
            it=mp.upper_bound(computer[i]);
            if(it!=mp.end())
            {
                it->second--;
                if(!(it->second))
                    mp.erase(it);
                cnt++;
            }
        }
        int ans=0;
        for(int i=you.size()-1;i>=0;i--)
        {
            if(!cnt)
                break;
            cnt--;
            ans+=you[i];
        }
        return ans;
	}
};