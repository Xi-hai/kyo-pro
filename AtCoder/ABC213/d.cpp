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

vector<bool> seen;
deque<int> visit_order;
vector<set<int>> graph;

void dfs(int v) {
    seen[v] = true;
    for (int nv : graph[v]) {
        if (seen[nv]) continue;
        visit_order.push_back(nv);
        dfs(nv);
        if (visit_order.back() != v) visit_order.push_back(v);
    }
    return;
}

int main() {
    int n, a, b; scanf("%d", &n);
    graph.assign(n, {});
    rep(n-1) {
        scanf("%d %d", &a, &b);
        a--; b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    visit_order.assign(1, 0);
    seen.assign(n, false);
    dfs(0);

    int m = visit_order.size();
    rep(i, m) printf((i<m-1 ? "%d " : "%d\n"), visit_order[i] + 1);
    return 0;
}