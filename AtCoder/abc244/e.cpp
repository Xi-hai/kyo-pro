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
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    s--, t--, x--;
    VVI graph(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // dp[i][j][b]: 頂点iまでの経路長がj, xの出現回数がb(=0/1)である経路の総数
    VVVL dp(n, VVL(k+1, VL(2)));
    dp[s][0][0] = 1;
    rep(j, k) {
        rep(b, 2) {
            rep(i, n) {
                if (dp[i][j][b] == 0) continue;

                for (int nv : graph[i]) {
                    if (nv == x) {
                        dp[nv][j+1][(b+1)%2] += dp[i][j][b];
                        dp[nv][j+1][(b+1)%2] %= MOD;
                    } else {
                        dp[nv][j+1][b] += dp[i][j][b];
                        dp[nv][j+1][b] %= MOD;
                    }
                }
            }
        }
    }

    // 出力はdp[t][k][0]
    cout << dp[t][k][0] << "\n";
    return 0;
}