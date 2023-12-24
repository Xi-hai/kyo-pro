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
    int h, w, n; scanf("%d %d\n%d", &h, &w, &n);
    VI a(n);
    rep(i, n) scanf("%d", &a[i]);
    VVI grid(h, VI(w));

    int color = 1, cnt = 0;
    rep(i, h) {
        rep(j, w) {
            if (i%2 == 0) grid[i][j] = color;
            else grid[i][w-1-j] = color;
            cnt++;
            if (cnt == a[color-1]) {
                cnt = 0;
                color++;
            }
        }
    }

    rep(i, h) rep(j, w) printf(j<w-1 ? "%d " : "%d\n", grid[i][j]);
    return 0;
}