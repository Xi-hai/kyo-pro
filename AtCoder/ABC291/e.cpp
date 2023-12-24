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

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {a = b; return true;}
    return false;
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {a = b; return true;}
    return false;
}

int main() {
    int n, m, x, y; scanf("%d %d", &n, &m);
    VVI graph(n);
    VI indeg_s(n), indeg_d(n);
    unordered_set<ll> st;
    rep(i, m) {
        scanf("%d %d", &x, &y);
        x--, y--;
        ll t = x*200000ll + y;
        if (!st.count(t)) {
            st.insert(t);
            graph[x].push_back(y);
            indeg_s[y]++;
            indeg_d[y]++;
        }
    }

    VI topol_s, topol_d;
    stack<int> stck;
    queue<int> q;
    rep(i, n) {
        if (indeg_d[i] == 0) {
            stck.push(i);
            q.push(i);
        }
    }

    while (!stck.empty()) {
        int v = stck.top();
        stck.pop();
        for (int &nv : graph[v]) {
            indeg_s[nv]--;
            if (indeg_s[nv] == 0) stck.push(nv);
        }
        topol_s.push_back(v);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int &nv : graph[v]) {
            indeg_d[nv]--;
            if (indeg_d[nv] == 0) q.push(nv);
        }
        topol_d.push_back(v);
    }

    VI ans(n);
    if (topol_d == topol_s) {
        rep(i, n) ans[topol_s[i]] = i+1;
        printf("Yes\n");
        rep(i, n) printf(i<n-1 ? "%d " : "%d\n", ans[i]);
    } else {
        printf("No\n");
    }
    return 0;
}