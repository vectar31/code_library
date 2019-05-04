#include <bits/stdc++.h>
#define MAX 1004 //number of applicants
#define N 100010 // number of jobs
using namespace std;
vector <int> bmpG[MAX];// there is an edge between u and v if uth applicant is interested in vth job;
int match[100005];
// An array to keep track of the applicants assigned to
// jobs. The value of matchR[i] is the applicant number
// assigned to job i, the value -1 indicates nobody is assigned.
bool bpm(int x, set <int> seen, int match[])
{
    for ( int i = 0; i < (int)bmpG[x].size(); i++ ) {
        if ( seen.find(bmpG[x][i]) == seen.end() ) {
            seen.insert(bmpG[x][i]);
            if ( match[bmpG[x][i]] == -1 || bpm(match[bmpG[x][i]], seen, match) ) {
                match[bmpG[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    // fill the graph bmpG with proper edges
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        bmpG[u].push_back(v);
    }
    memset(match, -1, sizeof(match));// Initially no job is assigned.
    for ( int i = 0; i < n; i++ )
    {
        set <int> seen;
        if ( bpm(i,seen,match) ) ans++;
    }
    cout << ans << endl;// maximum possible matchings
    return 0;
}
