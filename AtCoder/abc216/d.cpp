#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

int main() {
    int n, m; cin >> n >> m;
    VVI tube(m);
    VI k(m);
    rep(i, m) {
        cin >> k[i];
        tube[i].resize(k[i]);
        rep(j, k[i]) {
            cin >> tube[i][j];
            tube[i][j]--;
        }
    }

    VVI graph(n);
    VI indegree(n);
    rep(i, m) {
        rep(j, k[i]-1) {
            graph[ tube[i][j] ].push_back( tube[i][j+1] );
            indegree[ tube[i][j+1] ]++;
        }
    }

    queue<int> q;
    VI t_sorted;
    rep(i, n) {
        if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        t_sorted.push_back(v);
        for (int nv : graph[v]) {
            indegree[nv]--;
            if (indegree[nv] == 0) q.push(nv);
        }
    }

    int len = t_sorted.size();
    cout << (len == n ? "Yes\n" : "No\n");
    return 0;
}