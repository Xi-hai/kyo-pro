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
    int t; scanf("%d", &t);
    rep(t) {
        int n; scanf("%d", &n);
        VL m(n);
        VI s(n);
        rep(i, n) scanf("%lld %d", &m[i], &s[i]);
        ll time_both = INFI, time_skill1 = INFI, time_skill2 = INFI;
        rep(i, n) {
            if (s[i] == 11) chmin(time_both, m[i]);
            else if (s[i] == 10) chmin(time_skill1, m[i]);
            else if (s[i] == 1) chmin(time_skill2, m[i]);
        }

        ll ans = min(time_both, time_skill1 + time_skill2);
        printf(ans >= INFI ? "-1\n" : "%lld\n", ans);
    }
    return 0;
}