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
const ll MOD = 998244353;

int main() {
    int n, m, k, l, r; cin >> n >> m >> k;
    vector<vector<ll>> dp(n, vector<ll>(m+1)); // dp[i][j]=長さi+1の数列で、最後の項がjであるようなものの個数
    rep(i, 1, m+1) {
        dp[0][i] = 1;
    }

    vector<vector<ll>> sum(n, vector<ll>(m+1)); // dp[i]のj項目までの累積和
    rep(i, m+1) sum[0][i] = i;

    rep(i, 1, n) {
        rep(j, 1, m+1) {
            if (k == 0) {
                dp[i][j] = sum[i-1][m];
                continue;
            }
            l = j - k;
            r = j + k - 1;
            if (l > 0) {
                dp[i][j] = sum[i-1][l];
            }
            if (r < m) {
                if (sum[i-1][m] - sum[i-1][r] < 0) {
                    dp[i][j] += sum[i-1][m] - sum[i-1][r] + MOD;
                } else {
                    dp[i][j] += (sum[i-1][m] - sum[i-1][r]) % MOD;
                }
            }
            dp[i][j] %= MOD;
        }

        rep(j, 1, m+1) {
            sum[i][j] = (sum[i][j-1] + dp[i][j]) % MOD;
        }
    }

    cout << sum[n-1][m] << endl;
    return 0;
}