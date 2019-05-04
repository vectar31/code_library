#include <bits/stdc++.h>

using namespace std;
vector< pair<int , int> > events;
vector< pair<int , int> > schedule;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int st,ft;
        cin>>st>>ft;
        events.push_back(make_pair(ft,st));
    }
    sort(events.begin(),events.end());
    int lastfinishtime=0;
    for(int i=0;i<events.size();i++)
    {
        if(events[i].second>=lastfinishtime)
        {
            schedule.push_back(events[i]);
            lastfinishtime=events[i].first;
        }
    }
    for(int i=0;i<schedule.size();i++)
        cout<<schedule[i].second<<" "<<schedule[i].first<<endl;
    return 0;
}
