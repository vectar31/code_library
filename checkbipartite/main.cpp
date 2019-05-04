#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main()
{
    int bug,inter;int f=1;
    cin>>bug>>inter;
    vector < list<int> > a(bug);
    int color[bug];
    for(int i=0;i<bug;i++)
        color[i]=-1;

    for(int i=0;i<inter;i++)
    {
        int b1,b2;
        cin>>b1>>b2;
        a[b1-1].push_back(b2-1);
        a[b2-1].push_back(b1-1);
    }/*int c=0;
    vector <list<int> >::iterator it;
    for(it=a.begin();it!=a.end();it++)
        {
            cout<<"adjl of " <<c<<" is ";
            list<int> li = *it;
            list<int>::iterator iter;
            for(iter=li.begin();iter!=li.end();iter++)
                cout<<" "<<*iter;
            cout<<endl;
            c++;
        }*/
    list<int>::iterator iter;
    queue <int> q;
    q.push(0);color[0]=1;
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int t = q.front();
        q.pop();
        for(iter=a[t].begin();iter!=a[t].end();iter++)
        {
            //cout<<"color "<<color[0]<<" "<<color[1]<<" "<<color[2]<<" "<<endl;
            if(color[*iter]==-1)
            {
                color[*iter]=1-color[t];
                q.push(*iter);
            }
            else
            {
                if(color[*iter]==color[t])
                {
                    f=0;
                    break;
                }
            }
        }

        if(f==0)
            break;
    }
    if(f)
        cout<<"Bipartite";
    else
        cout<<"NOT";

    return 0;
}
