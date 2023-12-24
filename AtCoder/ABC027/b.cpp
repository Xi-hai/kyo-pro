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
    int n; scanf("%d", &n);
    VI a(n), s(n+1);
    rep(i, n) {
        scanf("%d", &a[i]);
        s[i+1] = s[i] + a[i];
    }

    if (s[n] % n != 0) {
        printf("-1\n");
        return 0;
    }

    int ans = 0, l = 0;
    rep(r, 1, n+1) {
        if ((s[r] - s[l]) * n == s[n] * (r - l)) {
            ans += r - l - 1;
            l = r;
        }
    }

    printf("%d\n", ans);
    return 0;
}