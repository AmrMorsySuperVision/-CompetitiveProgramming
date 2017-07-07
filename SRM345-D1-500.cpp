/*
	- The solution is greedy first for each player they take the first stone they can get in one move
	- After that if the number of stones is odd the first player can play optimally to get the rest of the treasure

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


class StoneGame {
public:
	int getScore(vector <int> treasure, vector <int> stones) {
		vector<int> one;
		long long tmp=0,x=0;
		for(int i=0;i<stones.size();i++)
            if(stones[i]==1)
            {
                x++;
                one.push_back(treasure[i]);
            }
            else
            {
                x+=stones[i];
                tmp+=treasure[i];
            }
        sort(one.begin(),one.end(),greater<int>());
        long long ans=0;
        for(int i=0;i<one.size();i+=2)
            ans+=one[i];
        if(x%2)
            ans+=tmp;
        return ans;
	}
};