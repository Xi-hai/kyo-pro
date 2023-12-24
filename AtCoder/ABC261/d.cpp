#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<ll, int> PLI;
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
    int n, m; scanf("%d %d", &n, &m);
    VL x(n+1), bonus(n+1);
    rep(i, 1, n+1) {
        scanf("%lld", &x[i]);
    }
    int c; ll y;
    rep(i, m) {
        scanf("%d %lld", &c, &y);
        bonus[c] = y;
    }

    VVL dp(n+1, VL(n+1, -INFL));
    dp[0][0] = 0, dp[1][0] = 0;
    rep(i, 1, n+1) {
        ll temp = dp[i][0];
        rep(j, 1, i+1) {
            dp[i][j] = dp[i-1][j-1] + x[i] + bonus[j];
            chmax(temp, dp[i][j]);
        }
        if (i<n) dp[i+1][0] = temp;
    }

    ll ans = -INFL;
    rep(j, n+1) chmax(ans, dp[n][j]);
    printf("%lld\n", ans);
    return 0;
}