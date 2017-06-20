/*
	  - The start of the search always increase or stay the same 
      - make a start index initially 0
      - on each word check if there's a match in the orginal string if there's update start 
      - if not add it to the end of the word and update start to the string size
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


class OrderedSuperString
{
public:
    int getLength(vector <string> words)
    {
        string s="";
        int last=0;
        for(int i=0; i<words.size(); i++)
        {
            bool check2=0;
            for(int j=last; j<s.size(); j++)
            {
                if(s[j]==words[i][0])
                {
                    int ind=j;
                    bool check=1;
                    for(int f=0; f<words[i].size() && ind<s.size() ; f++,ind++)
                        if(words[i][f]!=s[ind])
                        {
                            check=0;
                            break;
                        }
                    if(check)
                    {
                        check2=1;
                        last=j;
                        break;
                    }
                }
            }
            if(!check2)
                last=s.size();
            int ind=last;
            for(int j=0;j<words[i].size();j++)
            {
                if(ind>=s.size())
                {
                    ind++;
                    s+=words[i][j];
                }
                else
                    ind++;
            }
        }
        return s.size();
    }
};
