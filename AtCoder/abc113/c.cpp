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

int main() {
    int n, m; cin >> n >> m;
    VI p(m), y(m);
    rep(i, m) cin >> p[i] >> y[i];

    vector<vector<pair<int, int>>> sorted(n+1);
    rep(i, m) {
        sorted[p[i]].push_back({y[i], i});
    }
    rep(i, 1, n+1) sort(all(sorted[i]));
    VS id(m);
    rep(i, 1, n+1) {
        string id_top = to_string(i);
        id_top = string(max(0, 6-(int)id_top.size()), '0') + id_top;
        int len = sorted[i].size();
        rep(j, len) {
            string id_bottom = to_string(j+1);
            id_bottom = string(max(0, 6-(int)id_bottom.size()), '0') + id_bottom;
            id[ sorted[i][j].second ] = id_top + id_bottom;
        }
    }

    rep(i, m) cout << id[i] << "\n";
    return 0;
}