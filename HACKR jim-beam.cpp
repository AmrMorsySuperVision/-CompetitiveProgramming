/*
	    - Calculate the Cross product of on line to another 
        - it'll get the area of 2 different parallelogram 
        - if the 2 area's have a different signs this means it intersect else if the area equals to zero the point lie on the same line 
        so need to check if it is inside the segement 
*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point
{
    ll x;
    ll y;
};

bool onSegment(Point r, Point p, Point q)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return 1;
    return 0;
}

ll cp(Point b,Point a,Point c)
{
    return ((a.x-b.x)*(c.y-b.y))-((a.y-b.y)*(c.x-b.x));
}

bool re(ll a,ll b)
{
    if(a>0 && b<0)
        return 1;
    if(a<0 && b>0)
        return 1;
    return 0;
}

bool check(Point a,Point b,Point c,Point d)
{
    ll abc=cp(a,b,c);
    ll abd=cp(a,b,d);
    ll cda=cp(c,d,a);
    ll cdb=cp(c,d,b);
    //cout<<abc<<" "<<abd<<" "<<cda<<" "<<cdb<<" *** "<<endl;
    if(re(abc,abd) && re(cda,cdb))
        return 1;
    if(!abc && onSegment(a,b,c))
        return 1;
    if(!abd && onSegment(a,b,d))
        return 1;
    if(!cda && onSegment(c,d,a))
        return 1;
    if(!cdb && onSegment(c,d,b))
        return 1;
    return 0;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        ll x1,y1,x2,y2,xm,ym;
        cin>>x1>>y1>>x2>>y2>>xm>>ym;
        Point a,b,c,d;
        a.x=0;
        a.y=0;
        b.x=xm;
        b.y=ym;
        c.x=x1;
        c.y=y1;
        d.x=x2;
        d.y=y2;
        if(!check(a,b,c,d))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
