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

vector<bool> finished;
VI mem;
int num_linked;

void dfs(const VVI &G, int v, int cnt) {
    mem[v] = cnt;
    // printf("v=%d\n", v);
    for (auto nv : G[v]) {
        if (mem[nv] != -1) continue;
        dfs(G, nv, cnt);
    }
    finished[v] = true;
    return;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    VVI G(n);

    rep(i, m) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //各頂点に連結成分の番号をつける
    mem.assign(n, -1);
    finished.assign(n, false);
    num_linked = 0;
    rep(i, n) {
        if (finished[i]) continue;
        dfs(G, i, num_linked);
        num_linked++;
    }

    //連結成分ごとに大きさを調べ、閉路を持たない最大の辺の本数を求める
    int branch_max = 0;
    sort(all(mem));
    rep(i, n-1) {
        if (mem[i] == mem[i+1]) branch_max++;
    }

    printf("%d\n", m - branch_max);
    return 0;
}