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

int main() {
    int n, m, p; cin >> n >> m >> p;
    VL a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(all(b));
    VL subsum_b(m+1, 0); // b[i]までの部分和
    rep(i, m) subsum_b[i+1] = subsum_b[i] + b[i];

    ll ans = 0;
    rep(i, n) {
        int idx = lower_bound(all(b), p-a[i]) - b.begin();
        ans += a[i] * idx;
        ans += subsum_b[idx];
        ans += ((ll)p) * (m - idx);
    }
    cout << ans << "\n";
    return 0;
}