#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
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
    int N, S; cin >> N >> S;
    VI a(N+1), b(N+1);
    rep(i, 1, N+1) cin >> a[i] >> b[i];

    vector<vector<string>> dp(N+1, vector<string>(S+1));
    dp[0][0] = "A";
    //dp[i][j]:i番までのカードで和がSになる並べ方
    rep(i, 1, N+1) {
        rep(j, S+1) {
            if (j-a[i] >= 0 && dp[i-1][j-a[i]][0] == 'A') dp[i][j] = dp[i-1][j-a[i]] + 'H';
            if (j-b[i] >= 0 && dp[i-1][j-b[i]][0] == 'A') dp[i][j] = dp[i-1][j-b[i]] + 'T';
        }
    }

    if (dp[N][S][0] != 'A') printf("No\n");
    else {
        string ans = dp[N][S].substr(1);
        printf("Yes\n%s\n", ans.c_str());
    }
    return 0;
}