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

const int MAX_N = 200000;
int par[MAX_N];
int tree_rank[MAX_N];

//初期化
void init_uf(int n) {
    rep(i, n) {par[i] = i; tree_rank[i] = 0;}
}

//木の根を求める
int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}

//併合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x==y) return;
    
    if (tree_rank[x] < tree_rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (tree_rank[x] == tree_rank[y]) tree_rank[x]++;
    }
}

//判定
bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    //graph[i][j]: i番目のロープと結ばれたロープの番号
    init_uf(n);
    int a, c, roop = 0;
    char b, d;
    rep(m) {
        scanf("%d %c %d %c", &a, &b, &c, &d);
        a--, c--;
        if (same(a, c)) {
            roop++;
        }
        unite(a, c);
    }

    int s = 0;
    rep(i, n) {
        if (find(i) == i) s++;
    }

    printf("%d %d\n", roop, s-roop);
    return 0;
}