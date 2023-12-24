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
    int n; ll k; cin >> n >> k;
    VI a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;

    int cycle_start = -1, cycle_len = -1, cycle_end = -1, v = 0; // v := X mod N
    VI dist(n, -1);
    VL subsum(n);
    ll cycle_sum = 0;
    dist[0] = 0;
    while (cycle_len == -1) {
        ans += a[v];
        int nv = ans % n;
        k--;
        if (k == 0) break;
        if (dist[nv] == -1) {
            dist[nv] = dist[v] + 1;
            subsum[nv] = subsum[v] + a[v];
            v = nv;
        } else {
            cycle_start = nv;
            cycle_end = v;
            cycle_len = dist[v] - dist[nv] + 1;
            cycle_sum = subsum[v] + a[v] - subsum[v];
        }
    }

    if (k>0) {
        ll cycle_cnt = k/cycle_len;
        ans += cycle_cnt*cycle_sum;
        k %= cycle_len;
        int v = cycle_start;
        while (k>0) {
            ans += a[v];
            k--;
            v = ans % n;
        }
    }

    cout << ans << "\n";
    return 0;
}