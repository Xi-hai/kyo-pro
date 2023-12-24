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
    VL a(n);
    rep(i, n) scanf("%lld", &a[i]);
    VVL b(n, VL(2));
    b[0][0] = a[0];
    b[0][1] = -a[0];
    rep(i, 1, n) {
        b[i][0] = max(b[i-1][0] + a[i], b[i-1][1] - a[i]);
        b[i][1] = max(b[i-1][0] - a[i], b[i-1][1] + a[i]);
    }
    printf("%lld\n", b[n-1][0]);
    return 0;
}