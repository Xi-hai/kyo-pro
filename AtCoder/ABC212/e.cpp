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

const ll MOD = 998244353;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    VVI graph(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    VVL dp(k+1, VL(n)); // dp[i][j]: i日目に都市jにいる経路数
    dp[0][0] = 1;
    rep(i, k) {
        ll sum = 0;
        rep(j, n) {
            sum += dp[i][j];
            sum %= MOD;
        }

        rep(j, n) {
            ll broken = 0;
            for (int v : graph[j]) {
                broken += dp[i][v];
                broken %= MOD;
            }

            dp[i+1][j] += sum - broken - dp[i][j];
            dp[i+1][j] %= MOD;
            if (dp[i+1][j] < 0) dp[i+1][j] += MOD;
        }
    }

    cout << dp[k][0] << "\n";
    return 0;
}