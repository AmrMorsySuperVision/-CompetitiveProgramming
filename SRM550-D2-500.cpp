/*
	- Simulate it Once to get the max dimensions 
	- Simulate it for the second time to check if it rotate on valid cases

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
#include <bits/stdc++.h>

using namespace std;

int c=0;

class RotatingBot
{
public:
    int dirj[4]= {1,0,-1,0};
    int diri[4]= {0,-1,0,1};
    int grid[200][200];
    int mxi=0,mni=500,mxj=0,mnj=500;
    void setmx()
    {
        for(int i=2; i<198; i++)
            for(int j=2; j<198; j++)
                if(grid[i][j])
                {
                    mxi=max(mxi,i);
                    mni=min(mni,i);
                    mxj=max(mxj,j);
                    mnj=min(mnj,j);
                }
    }
    int minArea(vector <int> moves)
    {
        memset(grid,0,sizeof(grid));
        int curi=100,curj=100;
        grid[curi][curj]=1;
        bool check=0;
        int ind=0;
        for(int i=0; i<moves.size(); i++)
        {
            for(int j=0; j<moves[i]; j++)
            {
                curi+=diri[ind];
                curj+=dirj[ind];
                if(grid[curi][curj])
                    check=1;
                grid[curi][curj]=1;
            }
            ind++;
            ind%=4;
        }
        if(check)
            return -1;
        setmx();
        cout<<mxi<<" "<<mni<<" "<<mxj<<" "<<mnj<<endl;
        curi=100;
        curj=100;
        ind=0;
        if(c==5)
        {
            for(int i=90;i<120;i++)
            {
                for(int j=90;j<120;j++)
                    cout<<grid[i][j];
                cout<<endl;
            }
        }
        check=0;
        memset(grid,0,sizeof(grid));
        grid[100][100]=1;
        for(int i=0; i<moves.size(); i++)
        {
            for(int j=0; j<moves[i]; j++)
            {
                curi+=diri[ind];
                curj+=dirj[ind];
                grid[curi][curj]=1;
            }
            if( ! ((curi+diri[ind]>mxi || curj+dirj[ind]>mxj || curi+diri[ind]<mni || curj+dirj[ind]<mnj ) || grid[curi+diri[ind]][curj+dirj[ind]]==1) )
                if(i!=moves.size()-1)
                    check=1;
            if(c==5)
            cout<<curi<<" * "<<curj<<endl;
            ind++;
            ind%=4;
        }
        c++;
        if(check)
            return -1;
        return ((mxi-mni)+1)*((mxj-mnj)+1);
    }
};