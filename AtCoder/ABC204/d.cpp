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
    int n, sum = 0; scanf("%d", &n);
    VI t(n+1);
    rep(i, 1, n+1) {
        scanf("%d", &t[i]);
        sum += t[i];
    }
    
    vector<vector<bool>> dp(n+1, vector<bool>(100001, false));
    dp[0][0] = true;
    rep(i, 1, n+1) {
        rep(j, 100001) {
            if (dp[i-1][j]) {
                dp[i][j] = true;
                if (j+t[i] < 100001) dp[i][j+t[i]] = true;
            }
        }
    }

    rep(j, (sum+sum%2)/2, 100001) {
        if (dp[n][j]) {
            printf("%d\n", j);
            break;
        }
    }
    return 0;
}