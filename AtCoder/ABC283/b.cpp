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
    VI a(n);
    rep(i, n) scanf("%d", &a[i]);

    int q, t, k, x; scanf("%d", &q);
    rep(i, q) {
        scanf("%d %d", &t, &k);
        if (t == 1) {
            scanf("%d", &x);
            a[k-1] = x;
        } else printf("%d\n", a[k-1]);
    }
    return 0;
}