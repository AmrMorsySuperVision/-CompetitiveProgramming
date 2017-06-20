/*
	- Can't change the letter's order so each block between 2 letters can be solved spreadly
	- For each block counter the number of ? and if there's * mark a flag
	- Add first the * if the flag is true then add the number of ? found
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


class PatternOptimizer {
public:
	string optimize(string pattern) {
		pattern+='a';
		string op="";
		for(int i=0;i<pattern.size();i++)
        {
            if(isalpha(pattern[i]))
                op+=pattern[i];
            else
            {
                int cnt=0;
                bool check=0;
                for(i;i<pattern.size();i++)
                {
                    if(isalpha(pattern[i]))
                        break;
                    if(pattern[i]=='?')
                        cnt++;
                    else if(pattern[i]=='*')
                        check=1;
                }
                i--;
                if(check)
                    op+='*';
                for(int j=0;j<cnt;j++)
                    op+='?';
            }
        }
        op.pop_back();
        return op;
	}
};
