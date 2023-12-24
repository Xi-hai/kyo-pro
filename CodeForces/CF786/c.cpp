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
    int q; cin >> q;
    rep(test, q) {
        string s, t; cin >> s >> t;
        int m=s.size(), n=t.size();
        ll ans=1;

        int cnt_ta=0;
        rep(i, n) {
            if (t[i] == 'a') cnt_ta++;
        }
        if (cnt_ta>0) {
            if (n>1) ans = -1;
            goto OUT;
        }

        ans = ans << m;

        OUT:
        printf("%lld\n", ans);
    }
    return 0;
}