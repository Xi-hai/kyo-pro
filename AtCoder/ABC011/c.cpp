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

int main() {
    int n, itr=0; scanf("%d", &n);
    VI ng(3);
    rep(i, 3) scanf("%d", &ng[i]);

    VI dp(n+1, 10101);
    dp[0] = 0;

    rep(i, 1, n+1) {
        bool b=false;
        rep(j, 3) if (i == ng[j]) b=true;
        if (b) continue;
        dp[i] = min(dp[i], dp[i-1] + 1);
        if (i>1) dp[i] = min(dp[i], dp[i-2] + 1);
        if (i>2) dp[i] = min(dp[i], dp[i-3] + 1);
    }

    //rep(i, n+1) printf("i=%d: %d\n", i, dp[i]);
    printf(dp[n] > 100 ? "NO\n" : "YES\n");
    return 0;
}