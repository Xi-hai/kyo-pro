#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> VL;
#define rep(n) for (int i=0; i<(n); i++)
const ll INFL = 1LL << 60;

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {a = b; return true;}
    return false;
}

struct edge {int to; ll k, cost;};
typedef pair<ll, int> P; //first: 最短距離, second: 頂点番号

int main() {
    int n, m, start, goal;
    scanf("%d %d %d %d", &n, &m, &start, &goal);
    start--, goal--;
    vector<vector<edge>> graph(n);
    rep(m) {
        int a, b;
        ll t, k;
        scanf("%d %d %lld %lld", &a, &b, &t, &k);
        a--, b--;
        graph[a].push_back({b, k, t});
        graph[b].push_back({a, k, t});
    }
    
    VL dist(n, INFL);
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[start] = 0;
    pq.push(P(0, start));
    
    while (!pq.empty()) {
        P p = pq.top(); pq.pop();
        int v = p.second;
        if (dist[v] != p.first) continue;
        for (edge &e : graph[v]) {
            if (chmin(dist[e.to], (ll)ceil(dist[v]*1.0 / e.k) * e.k + e.cost)) {
                pq.push(P(dist[e.to], e.to));
            }
        }
    }

    printf(dist[goal] != INFL ? "%lld\n" : "-1\n", dist[goal]);
    return 0;
}