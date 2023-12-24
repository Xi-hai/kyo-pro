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
    int t; cin >> t;
    rep(test, t) {
        int n, m; cin >> n >> m;
        vector<string> s(n);
        rep(i, n) cin >> s[i];

        int ans=INFI;
        rep(i, n) {
            rep(j, i+1, n) {
                int dif=0;
                rep(k, m) {
                    dif += abs(s[i][k] - s[j][k]);
                }
                ans = min(ans, dif);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}