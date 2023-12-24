#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<ll, int> PLI;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {a = b; return true;}
    return false;
}

struct edge{int to, gain;};

int main() {
    int n, m; cin >> n >> m;
    VI height(n);
    rep(i, n) cin >> height[i];
    vector<vector<edge>> graph(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        if (height[u] < height[v]) swap(u, v); // uのほうが高い
        graph[u].push_back( {v, height[u] - height[v]} );
        graph[v].push_back( {u, 2*(height[v] - height[u]) } );
    }

    // dijkstra
    VL vals(n, -INFL);
    vals[0] = 0;
    priority_queue<PLI, vector<PLI>> pq; //{fun, from}
    pq.push({0, 0});

    while (!pq.empty()) {
        ll val = pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if (vals[from] > val) continue;

        for (edge &e : graph[from]) {
            ll t = vals[from] + e.gain;
            if (t > vals[e.to]) {
                vals[e.to] = t;
                pq.push({t, e.to});
            }
        }
    }

    ll ans = 0;
    rep(i, n) chmax(ans, vals[i]);
    cout << ans << "\n";
    return 0;
}