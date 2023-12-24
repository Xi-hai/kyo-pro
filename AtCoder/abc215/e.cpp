#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

const ll MOD = 998244353;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    // dp[i][j][k]: i回目までで既に出場した種類の組み合わせがj, 最後に出場した種類がk
    VVVL dp(n+1, VVL((1<<10), VL(11)));
    dp[0][0][0] = 1;
    rep(i, n) {
        int today = s[i] - 'A';
        dp[i+1] = dp[i];
        rep(j, (1<<10)) {
            rep(k, 11) {
                if (today+1 == k) {
                    dp[i+1][j][k] += dp[i][j][k];
                    dp[i+1][j][k] %= MOD;
                }
                // 同種のコンテストに不連続な出場はできない
                else if ((j >> today) & 1 == 1) continue;
                else { // 新たに種類todayのコンテストに出場
                    dp[ i+1 ][ j | (1<<today) ][ today+1 ] += dp[i][j][k];
                    dp[ i+1 ][ j | (1<<today) ][ today+1 ] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    rep(j, 1, (1<<10)) {
        rep(k, 1, 11) {
            ans += dp[n][j][k];
            ans %= MOD;
        }
    }
    cout << ans << "\n";

    return 0;
}