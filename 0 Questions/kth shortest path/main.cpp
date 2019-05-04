#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N  = 128;

template < class T, T INF >
struct dijkstra_kth_shortest_path {
    struct edge {
        int to;
        T w;
        edge(){}
        edge(int a, T b) {
            to=a;
            w=b;
        }
    };
    struct el {
        int vertex;
        T cost;
        el(){}
        el(int a, T b) {
            vertex=a;
            cost=b;
        }
        bool operator <(const el &a) const {
            return cost>a.cost;
        }
    };
    int n;
    vector < vector < edge > > v;
    void initialize(int k) {
        n=k;
        v.assign(n+1,vector < edge > ());
    }
    void add_edge(int from, int to, T w) {
        v[from].push_back(edge(to,w));
    }
    void run(int start, vector < T > *dist, int k) {
        int i,to;
        T current_distance,w;
        el curr;
        priority_queue < el > q;
        for(i=1;i<=n;i++) dist[i].clear();
        q.push(el(start,0));
        while(!q.empty()) {
            curr=q.top();
            q.pop();
            if((int)(dist[curr.vertex].size())>=k) continue;
            if(curr.cost>0) dist[curr.vertex].push_back(curr.cost);
            for(i=0;i<(int)(v[curr.vertex].size());i++) {
                to=v[curr.vertex][i].to;
                if((int)(dist[to].size())>=k) continue;
                w=v[curr.vertex][i].w;
                current_distance=w+curr.cost;
                q.push(el(to,current_distance));
            }
        }
    }
};

int tests,current_case;
int n,m;
dijkstra_kth_shortest_path < int, 1000000007 > d;
vector < int > dist[N][N];
int q;

void message(int current_case) {
    fprintf(stderr, "Case %d solved!\n", current_case);
}



int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int i,x,y,z;

    tests=1;
    //scanf("%d", &tests);
    //cin>>tests;
    for(current_case=1;current_case<=tests;current_case++) {
        scanf("%d %d", &n, &m);
        d.initialize(n);
        for(i=1;i<=m;i++) {
            scanf("%d %d %d", &x, &y, &z);
            d.add_edge(x,y,z);
        }
        for(i=1;i<=n;i++) {
            d.run(i,dist[i],100);
        }
        scanf("%d", &q);
        while(q--) {
            scanf("%d %d %d", &x, &y, &z);
            if((int)(dist[x][y].size())<z) {
                printf("-1\n");
            }
            else {
                printf("%d\n", dist[x][y][z-1]);
            }
        }

        MESSAGE:
        message(current_case);
    }

    return 0;
}
