/*

        - first run the permutation to get all points combinations
        - check the square properties on each combination
        - if the distance between every 2 consecutive points is equal and the angle between each consecutive line is 90 then answer is found return yes

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


class IsItASquare
{
public:
    int dis(pair<int,int> a,pair<int,int> b)
    {
        int ret=((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second));
        return ret;
    }
    pair<long double,long double> go(pair<long double,long double> a,pair<long double,long double> b)
    {
        return {b.first-a.first,b.second-a.second};
    }
    long double dot(pair<long double,long double> a,pair<long double,long double> b)
    {
        return (a.first*b.first)+(a.second*b.second);
    }
    long double norm(pair<long double,long double> a,pair<long double,long double> b)
    {
        return (sqrtl( (a.first*a.first)+ (a.second*a.second)) * sqrtl( (b.first*b.first)+ (b.second*b.second)) );
    }
    string isSquare(vector <int> x, vector <int> y)
    {
        vector<pair<int,int> > p;
        for(int i=0; i<4; i++)
            p.push_back({x[i],y[i]});
        sort(p.begin(),p.end());
        do
        {
            bool check=1;
            for(int i=0; i<4; i++)
                if(dis(p[(i+1)%4],p[i])!=dis(p[(i+1)%4],p[(i+2)%4]))
                    check=0;
            if(!check)
                continue;
            bool check2=1;
            for(int i=0; i<4; i++)
            {
                pair<long double,long double> va,vb;
                va=go(p[(i+1)%4],p[i]);
                vb=go(p[(i+1)%4],p[(i+2)%4]);
                long double angle=dot(va,vb)/norm(va,vb);
                if(angle!=0)
                    check2=0;
            }
            if(check2 && check)
                return "It's a square";
        }
        while(next_permutation(p.begin(),p.end()));
        return "Not a square";
    }
};
