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
    int n, k, d; scanf("%d %d %d", &n, &k, &d);
    VL a(n); rep(i, n) scanf("%lld", &a[i]);
    // dp[i][j][l]: i番目までのうちl個の項の和で、modDがjとなる最大値
    vector<VVL> dp(n+1, VVL(d, VL(k+1, -1)));
    dp[0][0][0] = 0;
    rep(i, n) {
        rep(j, d) {
            rep(l, k+1) {
                if (dp[i][j][l] >= 0){
                    chmax(dp[i+1][j][l], dp[i][j][l]);
                    if (l<k) chmax(dp[i+1][(j+a[i]) % d][l+1], dp[i][j][l] + a[i]);
                }
            }
        }
    }

    printf("%lld\n", dp[n][0][k]);
    return 0;
}