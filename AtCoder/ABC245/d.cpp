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
    int n, m; scanf("%d %d", &n, &m);
    VI a(n+1), c(n+m+1);
    rep(j, n+1) scanf("%d", &a[j]);
    rep(j, n+m+1) scanf("%d", &c[j]);

    VVI q(m+2, VI(m+1)), r(n+m+1, VI(n+m+1));
    rep(j, n+m+1) r[n+m][j] = c[j];

    for (int i=m; i>=0; i--) {
        rep(j, m+1) {
            q[i][j] = q[i+1][j];
        }
        q[i][i] += r[n+i][n+i] / a[n];

        rep(j, i, n+i) {
            r[n+i-1][j] = r[n+i][j] - r[n+i][n+i] / a[n] * a[j-i];
        }
        rep(j, i) {
            r[n+i-1][j] = r[n+i][j];
        }
    }

    rep(j, m+1) printf("%d ", q[0][j]);
    printf("\n");
    return 0;
}