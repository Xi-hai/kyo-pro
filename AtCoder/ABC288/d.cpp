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
    int n, k; scanf("%d %d", &n, &k);
    VI a(n+1), b(n+1), c(n+1);
    rep(i, 1, n+1) {
        scanf("%d", &a[i]);
        if (i < n - k + 2) b[i] = (i>=k ? b[i-k] : 0) - c[i-1] - a[i];
        c[i] = c[i-1] + b[i] - (i>=k ? b[i-k] : 0);
    }

    int Q, l, r; scanf("%d", Q);
    rep(Q) {
        scanf("%d %d", &l, &r);
        l--; r--;

    }
    return 0;
}