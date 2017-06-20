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


class grafixCorrupt {
public:
	int selectWord(vector <string> dictionary, string candidate) {
		int ans=-1,mx=0;
		for(int i=0;i<dictionary.size();i++)
        {
            int cnt=0;
            for(int j=0;j<candidate.size();j++)
                cnt+=(dictionary[i][j]==candidate[j]);
            if(cnt>mx)
            {
                mx=cnt;
                ans=i;
            }

        }
        return ans;
	}
};