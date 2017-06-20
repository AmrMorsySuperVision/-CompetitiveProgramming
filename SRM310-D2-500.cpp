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


class InputBoxChecker
{
public:
    vector <string> checkPrefix(int smallest, int largest, vector <int> numbers)
    {
        stringstream ss,tt;
        ss<<smallest;
        string small,big,num;
        ss>>small;
        tt<<largest;
        tt>>big;
        vector<string> v;
        for(int i=0; i<numbers.size(); i++)
        {
            stringstream mm;
            num="";
            mm<<numbers[i];
            mm>>num;
            if(num.size()>small.size())
            {
                if(numbers[i]>=smallest && numbers[i]<=largest)
                    v.push_back("VALID");
                else
                    v.push_back("INVALID");
            }
            else
            {
                bool check=0,check2=0;
                for(int i=0; i<num.size(); i++)
                    if(num[i]>small[i])
                    {
                        check2=1;
                        break;
                    }
                    else if(num[i]<small[i])
                    {
                        check=1;
                        break;
                    }
                if(check|| check2){
                    while(num.size()<small.size()+check)
                        num+='0';
                }
                else
                    num=small;
                stringstream hh;
                long long c;
                hh<<num;
                hh>>c;
                if(c>=smallest && c<=largest)
                    v.push_back("VALID");
                else
                    v.push_back("INVALID");
            }
        }
        return v;
    }
};