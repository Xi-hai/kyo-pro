#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
typedef vector<vector<int>> Graph;

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

int main() {
    ll n, a, b, ans; cin >> n >> a >> b;
    ans = (n+1) * n / 2;
    ll LCM = a * b / __gcd(a, b);
    ll cnt_amax = n / a, cnt_bmax = n / b, cnt_LCMmax = n / LCM;
    ans -= a * (cnt_amax + 1) * cnt_amax / 2;
    ans -= b * (cnt_bmax + 1) * cnt_bmax / 2;
    ans += LCM * (cnt_LCMmax + 1) * cnt_LCMmax / 2;
    cout << ans << endl;
    return 0;
}