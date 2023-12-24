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

const VI di = {-1, 0, 0, 1};
const VI dj = {0, -1, 1, 0};

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
    else if (par[x] == -1) return -1;
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
    const VI dx = {-w, -1, 1, w};
    VS grid(h);
    rep(i, h) cin >> grid[i];

    init_uf(h*w);
    int cnt_red = 0;
    rep(i, h) {
        rep(j, w) {
            int x = i*w + j;
            if ( grid[i][j] == '.' ) {
                par[x] = -1;
                cnt_red++;
                continue;
            }
            rep(k, 4) {
                if ( i+di[k] < 0 || h <= i+di[k] || j+dj[k] < 0 || w <= j+dj[k] ) continue;
                if ( grid[ i+di[k] ][ j+dj[k] ] == '.' ) continue;
                unite_uf(x, x+dx[k]);
            }
        }
    }

    set<int> st;
    rep(x, h*w) st.insert(find_uf(x));
    st.erase(-1);
    int count_connected = st.size();

    int sum = 0;
    rep(i, h) {
        rep(j, w) {
            if (grid[i][j] == '#') continue;
            set<int> st_cnt;
            rep(k, 4) {
                int x = i*w + j;
                if ( i+di[k] < 0 || h <= i+di[k] || j+dj[k] < 0 || w <= j+dj[k] ) continue;
                if ( grid[ i+di[k] ][ j+dj[k] ] == '.' ) continue;
                st_cnt.insert(find_uf(x+dx[k]));
            }
            sum += count_connected - st_cnt.size() + 1;
        }
    }

    // ans = sum / cnt_red;
    return 0;
}