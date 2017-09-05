/*
	- We can consider each consecutive white cells as one pile
	- The player that can't take any while cell from any pile lose
	- Count the number of consecutive white cells and Xor them
	
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


class CatAndRabbit {
public:
	string getWinner(string tiles) {
		vector<int> nums;
		if(tiles.find('#')==-1 || tiles.find('.')==-1)
            return "Rabbit";
		tiles+='#';
		int cnt=0;
		for(int i=0;i<tiles.size();i++)
        {
            if(tiles[i]=='#')
            {
                if(cnt)
                nums.push_back(cnt);
                cnt=0;
            }
            if(tiles[i]=='.')
                cnt++;
        }
        int tmp=0;
        for(int i=0;i<nums.size();i++)
            tmp^=nums[i];
        if(tmp)
            return "Cat";
        return "Rabbit";
	}
};
