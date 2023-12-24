//#define _GLIBCXX_DEBUG
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
    int t; cin >> t;
    rep(t) {
        int m, s, b_max = 0; cin >> m >> s;
        VI b(m);
        rep(i, m) {
            cin >> b[i];
            b_max = max(b_max, b[i]);
        }

        int s_append = b_max * (b_max+1) / 2;
        bool ans = true;
        rep(i, m) s_append -= b[i];
        if (s_append == s) goto OUT;
        rep(i, b_max+1, 100) {
            s_append += i;
            if (s_append < s) continue;
            if (s_append > s) ans = false;
            break;
        }

        OUT:
        printf(ans ? "YES\n" : "NO\n");
    }
    return 0;
}