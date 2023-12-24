#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

const int MAX_N = 101010;
int par[MAX_N];
int tree_rank[MAX_N];
int sizeof_union[MAX_N];

//初期化
void init_uf(int n) {
    rep(i, n) {
        par[i] = i;
        tree_rank[i] = 0;
        sizeof_union[i] = 1;
    }
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
        sizeof_union[y] += sizeof_union[x];
    } else {
        par[y] = x;
        sizeof_union[x] += sizeof_union[y];
        if (tree_rank[x] == tree_rank[y]) tree_rank[x]++;
    }
}

//判定
bool same_uf(int x, int y) {
    return find_uf(x) == find_uf(y);
}

struct edge {int cost, from, to;};
bool comp(const edge& a, const edge& b) {
    return a.cost < b.cost;
}

int main() {
    int n; cin >> n;
    int u, v, w;
    vector<edge> graph;
    rep(n-1) {
        cin >> u >> v >> w;
        graph.push_back({w, u, v});
    }
    sort(all(graph), comp);

    ll ans = 0;
    init_uf(n);
    rep(i, n-1) {
        int cost = graph[i].cost;
        int u = graph[i].from, v = graph[i].to;
        u = find_uf(u);
        v = find_uf(v);
        ans += (ll)cost * sizeof_union[u] * sizeof_union[v];
        unite_uf(u, v);
    }
    cout << ans << "\n";
    return 0;
}