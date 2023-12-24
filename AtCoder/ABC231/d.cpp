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
    VVI graph(n);
    rep(m) {
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool ans = true;
    vector<bool> used(n, false);
    VI lines;
    stack<int> st;
    rep(i, n) {
        int t = graph[i].size();
        if (t > 2) {
            ans = false;
            goto END;
        }
        if (t < 2) st.push(i);
    }

    while (!st.empty()) {
        int v = st.top(); st.pop();
        if (used[v]) continue;
        lines.push_back(v);
        used[v] = true;
        for (int nv : graph[v]) {
            if (!used[nv]) st.push(nv);
        }
    }
    if ((int)lines.size() < n) ans = false;

    END:
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}