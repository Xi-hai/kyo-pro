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

const int MOD = 840;

int main() {
    int n, query;
    ll x, y;
    cin >> n >> x >> y;
    VI p(n-1);
    VL t(n-1);
    rep(i, n-1) cin >> p[i] >> t[i];
    cin >> query;
    VL q(query);
    rep(i, query) cin >> q[i];

    VL time(MOD, x);
    rep(i, MOD) {
        time[i] += i;
        rep(j, n-1) {
            int to_ceil = (time[i] % p[j] > 0);
            time[i] = (time[i] / p[j] + to_ceil) * p[j];
            time[i] += t[j];
        }
        time[i] += y - i;
    }

    rep(i, query) {
        cout << q[i] + time[ q[i] % MOD ] << "\n";
    }
    return 0;
}