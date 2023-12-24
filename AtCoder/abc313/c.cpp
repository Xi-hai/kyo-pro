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

const ll INFL = (1LL << 60);

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
    int n; cin >> n;
    ll sum = 0;
    VL a(n);
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    ll avg = floor(1.0 * sum / n);
    ll over = sum - (avg * n);
    sort(all(a));
    VL b(n);
    rep(i, n) {
        b[i] = (i < n - over) ? avg : avg + 1;
    }

    ll ans = 0;
    rep(i, n) {
        ans += abs(a[i] - b[i]);
    }
    cout << ans / 2 << "\n";
    return 0;
}