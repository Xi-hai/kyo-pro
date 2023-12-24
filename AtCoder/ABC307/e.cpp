#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
const ll MOD = 998244353;

int main() {
    ll n, m; scanf("%lld %lld", &n, &m);
    VL dp(n), mpow(n);
    mpow[0] = m;
    rep(i, 1, n) {
        mpow[i] = mpow[i-1] * (m-1);
        mpow[i] %= MOD;
    }

    dp[0] = m;
    dp[1] = mpow[1];
    rep(i, 2, n) {
        dp[i] = mpow[i] - dp[i-1];
        dp[i] %= MOD;
        if (dp[i] < 0) dp[i] += MOD;
    }

    printf("%lld\n", dp[n-1]);
    return 0;
}