#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Graph;
typedef vector<vector<int>> DPI;
typedef vector<vector<ll>> DPL;
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

int main() {
    ll x, a, d, n;
    cin >> x >> a >> d >> n;

    if (d==0) {
        cout << abs(x-a) << endl;
        return 0;
    }

    if (d < 0) {
        a = a + d * (n-1);
        d = -d;
    }

    ll i = (x-a) / d;
    auto f = [&](ll i) {
        if (i>=n) i = n-1;
        if (i<0) i = 0;
        return a+d*i;
    };

    ll ans = min(abs(f(i)-x), abs(f(i+1)-x));
    cout << ans << endl;
    return 0;
}