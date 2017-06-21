/*
	Thales' theorem state that each diameter connected to any point to the circle form a right angle triangle
	- Generate the points
	- for each point check if there's opposite one if there's add to the answer number of points-2 


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

typedef long long ll;

class RightTriangle
{
public:
    long long triangleCount(int places, int points, int a, int b, int c)
    {
        bool red[places];
        memset(red,0,sizeof(red));
        set<ll> se;
        for(ll i=0;i<places;i++)
            se.insert(i);
        set<ll>::iterator it;
        for(ll i=0;i<points;i++)
        {
            ll x=(a*i*i + b*i + c) % places;
            it=se.lower_bound(x);
            if(it==se.end())
                it=se.begin();
            red[(*it)]=1;
            se.erase(it);
        }
        long long ans=0;
        for(ll i=0; i<places/2; i++)
            if(red[i]&& (i+places)%2==(i%2) && red[i+places/2])
                ans+=(points-2);
        return ans;
    }
};