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