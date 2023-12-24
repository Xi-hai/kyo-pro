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
// const ll MOD = 998244353;

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<vector<ll>> a(N, vector<ll>(0));
    vector<int> L(N);
    rep(i, N) {
        cin >> L[i];
        a[i] = vector<ll>(L[i]);
        rep(j, L[i]) cin >> a[i][j];
    }

    vector<map<ll, int>> dp(N+1);
    dp[0][X] = 1;
    rep(i, N) {
        rep(j, L[i]) {
            for (auto p : dp[i]) {
                if (p.first % a[i][j] == 0) {
                    dp[i+1][p.first / a[i][j]] += p.second;
                }
            }
        }
    }

    cout << dp[N][1] << endl;
    return 0;
}