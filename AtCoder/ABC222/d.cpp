#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> GraphI;
typedef vector<VI> DPI;
typedef vector<VL> DPL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
const ll MOD = 998244353;

int main() {
    int N; cin >> N;
    vector<int> a(N+1), b(N+1);
    rep(i, 1, N+1) cin >> a[i];
    rep(i, 1, N+1) cin >> b[i];

    // dp[i][j]: a[i]<=j<=b[i] かつ c[i-1]<=c[i](=j) を満たす, i項の数列の個数
    DPL dp(N+1, VL(3001));
    DPL sum(N+1, VL(3001));
    dp[0][0] = 1;

    rep(i, N+1) {
        rep(j, 3001) {
            if (i>0 && a[i] <= j && j <= b[i]) {
                dp[i][j] = sum[i-1][j];
            }

            if (j>0) {
                sum[i][j] = sum[i][j-1] + dp[i][j];
            } else {
                sum[i][j] = dp[i][j];
            }
            sum[i][j] %= MOD;
        }
    }
    
    cout << sum[N][3000] << endl;
    return 0;
}