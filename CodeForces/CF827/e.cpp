//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
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
    int t; //cin >> t;
    scanf("%d", &t);
    rep(t) {
        int n, q; //cin >> n >> q;
        scanf("%d %d", &n, &q);
        VL a(n), k(q), sum(n+1);
        ll a_max = 0;
        rep(i, n) {
            // cin >> a[i];
            scanf("%lld", &a[i]);
            sum[i+1] = sum[i] + a[i];
            if (a_max < a[i]) a_max = a[i];
            else a[i] = a_max;
        }

        rep(i, q) {
            // cin >> k[i];
            scanf("%lld", &k[i]);
            printf("%lld", sum[upper_bound(all(a), k[i]) - a.begin()]);
            printf((i<q-1) ? " " : "\n");
        }
    }
    return 0;
}