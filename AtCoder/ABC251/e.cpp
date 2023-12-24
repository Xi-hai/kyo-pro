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
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    //行動1を行わない場合
    vector<vector<ll>> dp1(n, vector<ll>(2));
    dp1[0][1] = INFL;
    rep(i, 1, n) {
        dp1[i][0] = dp1[i-1][1];
        dp1[i][1] = min(dp1[i-1][0], dp1[i-1][1]) + a[i];
    }
    ll ans = dp1[n-1][1];

    //行動1を行う場合
    vector<vector<ll>> dp2(n, vector<ll>(2));
    dp2[0][0] = INFL;
    dp2[0][1] = a[0];
    rep(i, 1, n) {
        dp2[i][0] = dp2[i-1][1];
        dp2[i][1] = min(dp2[i-1][0], dp2[i-1][1]) + a[i];
    }
    ans = min(ans, min(dp2[n-1][0], dp2[n-1][1]));

    printf("%lld\n", ans);
    return 0;
}