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
#define rrep(i, a, b) for (int i=(a-1); i>=(b); i--)

const int MAX_N = 201010;
int par[MAX_N];
int tree_rank[MAX_N];

//初期化
void init_uf(int n) {
    rep(i, n) {par[i] = i; tree_rank[i] = 0;}
}

//木の根を求める
int find_uf(int x) {
    if (par[x] == x) return x;
    else return par[x] = find_uf(par[x]);
}

//併合
void unite_uf(int x, int y) {
    x = find_uf(x);
    y = find_uf(y);
    if (x==y) return;
    
    if (tree_rank[x] < tree_rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (tree_rank[x] == tree_rank[y]) tree_rank[x]++;
    }
}

//判定
bool same_uf(int x, int y) {
    return find_uf(x) == find_uf(y);
}

int main() {
    int n, m; cin >> n >> m;
    VVI graph(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    init_uf(n);
    VI ans(n+1);
    int cnt = 0;
    rrep(i, n, 0) {
        cnt++;
        for (int nv : graph[i]) {
            if (nv < i) continue;
            if ( !same_uf(i, nv) ) {
                cnt--;
                unite_uf(i, nv);
            }
        }
        ans[i] = cnt;
    }
    
    rep(i, 1, n+1) {
        cout << ans[i] << "\n";
    }
    return 0;
}