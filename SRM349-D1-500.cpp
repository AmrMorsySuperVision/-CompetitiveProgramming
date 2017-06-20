/*
	-First my idea was to memorize but could figure how after reading the first 2 lines in the tutorial I starting looking for the building table solution
	The solution is similar to the one in the tutorial ==> 
	" The most common approach to the problem goes something like this: How many formations can be made is the number of
	non-decreasing sequences that can be made from the dice. So, how do we get the number of such sequences? If we consider 
	the possible values that end (or start) the sequence, then we know that the previous (or next) n-1 terms of the sequence 
	must all be less than or equal to this value. This leads us to a fairly straightforward DP solution (shown below). "
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
#include<bits/stdc++.h>

using namespace std;


class DiceGames {
public:
	long long countFormations(vector <int> sides) {
	    sort(sides.begin(),sides.end());
		long long dp[sides.size()][sides[sides.size()-1]+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=sides[0];i++)
            dp[0][i]=1;
        for(int i=1;i<sides.size();i++)
            for(int j=1;j<=sides[i];j++)
                for(int k=1;k<=j;k++)
                    dp[i][j]+=dp[i-1][k];
        long long ans=0;
        for(int i=1;i<=sides[sides.size()-1];i++)
            ans+=dp[sides.size()-1][i];
        return ans;
	}
};
