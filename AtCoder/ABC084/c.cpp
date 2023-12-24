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
    int n; scanf("%d", &n);
    VI c(n-1), s(n-1), f(n-1);
    rep(i, n-1) scanf("%d %d %d", &c[i], &s[i], &f[i]);

    rep(i, n-1) {
        int time = 0;
        rep(j, i, n-1) {
            if (time <= s[j]) time = s[j] + c[j];
            else time = s[j] + ceil((time - s[j])*1.0 / f[j])*f[j] + c[j];
        }
        printf("%d\n", time);
    }
    printf("0\n");
    return 0;
}