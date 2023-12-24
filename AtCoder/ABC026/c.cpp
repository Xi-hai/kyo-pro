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
VI salary;
void dfs(const VVI &G, int v) {
    seen[v] = true;
    int maximum = 0, minimum = INFI;

    if (G[v].size() == 0) {
        salary[v] = 1;
        return;
    }
    for (int nv : G[v]) {
        if (seen[nv]) continue;
        dfs(G, nv);
        maximum = max(maximum, salary[nv]);
        minimum = min(minimum, salary[nv]);
    }
    salary[v] = maximum + minimum + 1;
}

int main() {
    int n; scanf("%d", &n);
    VVI graph(n);
    rep(i, 1, n) {
        int boss;
        scanf("%d", &boss);
        graph[boss-1].push_back(i);
    }

    seen.assign(n, false);
    salary.assign(n, 0);
    dfs(graph, 0);

    printf("%d\n", salary[0]);
    return 0;
}