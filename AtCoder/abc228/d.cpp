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

const int N = (1 << 20);
int par[N];
int tree_rank[N];

//初期化
void init_uf(int n) {
    rep(i, n) {par[i] = i; tree_rank[i] = 0;}
}

//木の根を求める
int find_uf(int x) {
    if (par[x] == x) return x;
    else return par[x] = find_uf(par[x]);
}

//xをyに併合
void unite_uf(int x, int y) {
    x = find_uf(x);
    y = find_uf(y);
    if (x==y) return;
    par[x] = y;
}

//判定
bool same_uf(int x, int y) {
    return find_uf(x) == find_uf(y);
}

int main() {
    init_uf(N);
    VL a(N, -1);
    int query; cin >> query;
    rep(query) {
        int t; ll x;
        cin >> t >> x;
        if (t == 1) {
            int h = x%N;
            h = find_uf(h);
            a[h] = x;
            unite_uf(h, (h+1)%N);
        } else {
            cout << a[x%N] << "\n";
        }
    }
    return 0;
}