#include <bits/stdc++.h>
#define MAXVAL (1<<30)
#define N 1000010

using namespace std;
typedef pair <int,int> pii;
set<pii> s;
set <pair<pii,pii> > a;
int main()
{
    for(int i=0;i<4;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        s.insert({x1,y1});s.insert({x2,y2});
        a.insert({{x1,y1},{x2,y2}});
    }
    if(s.size()!=4)
        cout<<"NO"<<endl;
    else
    {
        int xmin=1e9+10;
        int xmax=-xmin,ymin=xmin,ymax=-xmin;
        for(auto it=s.begin();it!=s.end();it++)
        {
            pii temp=*it;
            xmin=min(xmin,temp.first);
            ymin=min(ymin,temp.second);
            xmax=max(xmax,temp.first);
            ymax=max(ymax,temp.second);
        }
        if(xmin==xmax || ymin==ymax)
            cout<<"NO"<<endl;
        else
        {
            bool f=1;
            if( a.find({{xmin,ymin},{xmax,ymin}})==a.end() && a.find({{xmax,ymin},{xmin,ymin}})==a.end() )
                f=0;
            if( a.find({{xmin,ymax},{xmax,ymax}})==a.end() && a.find({{xmax,ymax},{xmin,ymax}})==a.end() )
                f=0;
            if( a.find({{xmin,ymin},{xmin,ymax}})==a.end() && a.find({{xmin,ymax},{xmin,ymin}})==a.end() )
                f=0;
            if( a.find({{xmax,ymin},{xmax,ymax}})==a.end() && a.find({{xmax,ymax},{xmax,ymin}})==a.end() )
                f=0;
            if(f)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
