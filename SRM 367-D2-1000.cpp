/*
        - I always need to begin from the start of the offset and end at the nearst ciel value
        - sort the offsets
        - make a pointer marks the end of data 
        - Count the number of blocks needed for the current offset if the pointer is less that the offset then set the pointer = offset 
        - else let the pointer be the offset

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


class ProgrammingDevice
{
public:
    int minPackets(vector <int> offset, vector <int> size, int maxData)
    {
        vector<pair<long long,long long> > arr;
        for(int i=0; i<offset.size(); i++)
            arr.push_back({offset[i],size[i]});
        sort(arr.begin(),arr.end());
        long long start=0,ans=0,req,cnt;
        for(int i=0;i<arr.size();i++)
        {
            start=max(start,arr[i].first);
            req=(arr[i].first+arr[i].second)-start;
            if(req<=0)
                continue;
            cnt= (((arr[i].first+arr[i].second)-start)+maxData-1)/maxData;
            ans+=cnt;
            start+=cnt*maxData;
        }
        return ans;
    }
};
