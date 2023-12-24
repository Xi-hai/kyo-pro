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
    int n, x, y; scanf("%d\n%d %d", &n, &x, &y);
    VI a(n), b(n);
    rep(i, n) scanf("%d %d", &a[i], &b[i]);

    vector<VVI> dp(n+1, VVI(301, VI(301, INFI)));
    dp[0][0][0] = 0;
    rep(i, n) {
        rep(j, 301) {
            rep(k, 301) {
                if (dp[i][j][k] == INFI) continue;
                chmin(dp[i+1][j][k], dp[i][j][k]);
                chmin( dp[i+1][ min(x, j+a[i]) ][ min(y, k+b[i]) ] , dp[i][j][k]+1);
            }
        }
    }

    printf("%d\n", (dp[n][x][y] != INFI ? dp[n][x][y] : -1));
    return 0;
}