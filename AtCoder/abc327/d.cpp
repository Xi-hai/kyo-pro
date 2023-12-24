#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

int main() {
    int n, m; cin >> n >> m;
    VI a(m), b(m);
    VVI graph(n);
    rep(i, m) cin >> a[i];
    rep(i, m) {
        cin >> b[i];
        a[i]--, b[i]--;
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }

    bool ans = true;
    VI nodes(n, -1);
    rep(i, n) {
        queue<int> q;
        q.push(i);
        if (nodes[i] == -1) nodes[i] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int nv : graph[v]) {
                if (nodes[nv] == nodes[v]) {
                    ans = false;
                    goto OUT;
                }
                else if (nodes[nv] == -1) {
                    nodes[nv] = 1 - nodes[v];
                    q.push(nv);
                }
            }
        }
    }

    OUT:
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}