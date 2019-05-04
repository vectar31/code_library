/*
http://codeforces.com/contest/9/problem/E

Add minimum no, of edges (lexicographically smallest)  to the graph such that:
:each of its vertices belongs to one cycle only
:the  goes through all the vertices just once

Solution:
The cycle will consist of n vertices and n edges. If there is another edge except for these n,
then the vertices it connects belong to more than one cycle.
A graph is such a cycle if and only if the following conditions hold:
A1. The degree of each vertex equals 2.
A2. The graph is connected.
 Now let's figure out when a graph is not yet such cycle, but can be transformed into such cycle by adding edges.
 There are obvious necessary conditions:
B1. m < n.
B2. There are no cycles.
B3. The degree of each vertex is not more than 2.
 Let's add edges so that these conditions were preserved, and the sequence of edges was lexicographically minimal.
 So, we add an edge (i,j) such that:
1. The degrees of i and j are less than 2. (Otherwise we would break B3).
2. i and j belong to different connected components. (Otherwise we would break B2).
3. The pair (i,j) is lexicographically minimal.
 Let's see what we have when we can't add edges anymore. Since there are no cycles, each connected component is a tree,
 and therefore has at least one vertex with degree less than 2.
 If there are two connected components, then they could be connected by an edge without breaking B1-B3.
 So the graph is connected, has no cycles, and the degree of each vertex is not more than 2.
 This means that the obtained graph is just a walk and we can connect its end points to obtain such cycle.

 To summarize, the algorithm is the following:
 1. Check if A1-A2 hold. If yes, output "YES" and 0.
 2. Check if B1-B3 hold. If no, output "NO".
 3. Output "YES" and n-m.
 4. Add edges as described. When the edge (i,j) is added, output "i j".
 5. Find the only vertices i and j with degree less than 2 (they can be equal if n=1). Output "i j".
*/
#include <bits/stdc++.h>
#define N 100
#define ll long long

using namespace std;
vector <vector <int> >G(N);
int d[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>>v;
        G[u].push_back(v);G[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    if(m>=n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        if(d[i]>2)
        {
            cout<<"NO"<<endl;
            return 0;
        }

    return 0;
}
