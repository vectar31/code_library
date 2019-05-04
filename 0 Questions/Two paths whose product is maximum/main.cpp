/*
Find two independent paths(no common vertex) whose product of lengths is maximum.
Solution:
The only observation you need: for a rooted tree,
it's always possible to pick some vertex such that one path from answer is completely within subtree of this vertex,
and other path is completely outside.

With this observation, we can find length of longest path in a subtree and outside a subtree for every vertex,
and then simply try their combination for every vertex.

Now we'll use DP to find these longest paths.

First part sounds easier. For every vertex there are two possibilities -
either longest path in its subtree doesn't go through this vertex (in this case we can take result from one of sons),
or it goes through this vertex - in this case its a combination of two longest pathes starting from this vertex and going in different subtrees, or a single such path in case our vertex has only one son.
Therefore if we'll keep additional DP telling us longest path starting in given vertex and going in its subtree - we can already solve first part of our original problem.

Second part is a bit more complicated. Again there are several possibilities -
longest path outside a subtree of given vertex can be either outiside a subtree of parent,
or in a subtree of our parent (but in subtree of some other son), or it can go through our parent.
First case is simple - at the moment we solve given vertex, we should have that value calculated already.
Easy way to solve second case is  to store a set of longest pathes in subtree of a vertex.
Now when we go in a son of a vertex - we remove it from a set (to be sure we'll not take this son),
and when we'll return back to a parent vertex - we'll add it back. Taking maximum element from a set is easy :)
This idea leads to log(N) factor in complexity, so there is a risk to get TL. You can make it run in linear time,
yet with a big hidden constant, by implementing your own structure to maintain several largest values among sons of given vertex.

We are left with very last case - when longest path outside goes through parent.
It can be a longest path starting in a parent and going in subtree of some son (different from our current vertex),
combined with longest path starting in parent and going outside its subtree,
or a combination of two pathes starting in a parent and going through two different sons -
similar to a case from first part of our solution, but now we have one banned subtree.
Once again, we can either use trick with set or maintain information about 3 best values for parent
(we'll either need 1st+2nd, if result for current vertex isn't among these two, or 1st+3rd/2nd+3rd sometimes)
*/


#include <bits/stdc++.h>
#define endl '\n'
const int N = 200000;

using namespace std;

int n;
vector<int> g[N];

int in_subtree[N], max_down[N];
multiset<int> down_chains[N];
multiset<int>::iterator it;
int best_outside[N], longest_up[N];
long long ans;

pair<int, int> best_sub[N][3];

void dfs(int v, int p)
{
    vector<int> chains;

    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (to == p)
            continue;
        dfs(to, v);
        max_down[v] = max(max_down[v], max_down[to] + 1);

        if (in_subtree[to]>best_sub[v][0].first)
        {
            best_sub[v][1] = best_sub[v][0];
            best_sub[v][0] = make_pair(in_subtree[to], to);
        }
        else if (in_subtree[to] > best_sub[v][1].first)
        {
            best_sub[v][1] = make_pair(in_subtree[to], to);
        }

        down_chains[v].insert(max_down[to] + 1);
        in_subtree[v] = max(in_subtree[v], in_subtree[to]);
    }
    in_subtree[v] = max(in_subtree[v], max_down[v]);

    if (down_chains[v].size() > 1)
    {
        int s = 0;
        it = down_chains[v].end();
        --it;
        s += (*it);
        --it;
        s += (*it);
        in_subtree[v] = max(in_subtree[v], s);
    }

}

void solve(int v, int p)
{
    if (v != 1)
    {
        longest_up[v] = max(longest_up[v], longest_up[p] + 1);
        best_outside[v] = max(best_outside[v], best_outside[p]);
        best_outside[v] = max(best_outside[v], longest_up[p]);
        if (down_chains[p].size() > 0)
        {
            it = down_chains[p].end();
            --it;
            best_outside[v] = max(best_outside[v], longest_up[p] + (*it));
            longest_up[v] = max(longest_up[v], 1 + (*it));
            if (best_sub[p][0].second == v)
                best_outside[v] = max(best_outside[v], best_sub[p][1].first);
            else
                best_outside[v] = max(best_outside[v], best_sub[p][0].first);
        }
        if (down_chains[p].size() > 1)
        {
            int s = 0;
            it = down_chains[p].end();
            --it;
            s += *it;
            --it;
            s += *it;
            best_outside[v] = max(best_outside[v], s);
        }
    }

    ans = max(ans, 1ll * best_outside[v] * in_subtree[v]);

    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (to == p)
            continue;
        down_chains[v].erase(down_chains[v].find(max_down[to] + 1));
        solve(to, v);
        down_chains[v].insert(max_down[to] + 1);
    }
}

int main()
{
   // ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);

    solve(1, 0);

    cout << ans << endl;

   return 0;
}
