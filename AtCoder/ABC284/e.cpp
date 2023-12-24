#define _GLIBCXX_DEBUG
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
#define all(obj) (obj).begin(), (obj).end()

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

int main() {
    int n, m, u, v; scanf("%d %d", &n, &m);
    VVI G(n);
    rep(i, m) {
        scanf("%d %d", &u, &v);
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    VI dist(n, -1);
    stack<int> st;
    st.push(0);
    int count = 0;
    while (!st.empty()) {
        int v = st.top();
        if (dist[v] != -1) {
            st.pop();
            dist[v] = -1;
            continue;
        }
        count++;
        if (count == 1000000) break;
        for (int nv : G[v]) {
            if (dist[nv] == -1) {
                st.push(nv);
            }
        }
        dist[v] = 1;
    }

    printf("%d\n", count);
    return 0;
}