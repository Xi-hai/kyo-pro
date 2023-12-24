#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
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
const VI dy = {0, 1, 0, -1};
const VI dx = {1, 0, -1, 0};
const VI dy8 = {0, 1, 1, 1, 0, -1, -1, -1};
const VI dx8 = {1, 1, 0, -1, -1, -1, 0, 1};

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

const int MAX_N = 1000000;
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
    int h, w; cin >> h >> w;
    VS s(h);
    rep(i, h) cin >> s[i];
    init_uf(h*w);

    rep(i, h) {
        rep(j, w) {
            int v = i*w + j;
            if (s[i][j] != '#') continue;

            rep(k, 8) {
                if (i+dy8[k] < 0 || h <= i+dy8[k] || j+dx8[k] < 0 || w <= j+dx8[k]) continue;
                if (s[ i+dy8[k] ][ j+dx8[k] ] != '#') continue;
                int nv = v + dy8[k]*w + dx8[k];
                unite_uf(v, nv);
            }
        }
    }

    int ans = 0;
    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == '#' && par[i*w + j] == i*w + j) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}