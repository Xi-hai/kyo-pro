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
    int t; scanf("%d", &t);
    rep(t) {
        int n; scanf("%d", &n);
        VL a(n);
        int cnt_minus = 0;
        ll min_val = INFL, min_abs = INFL;
        bool zero = false;
        rep(i, n) {
            scanf("%lld", &a[i]);
            if (a[i] < 0) cnt_minus++;
            else if (a[i] == 0) zero = true;
            min_val = min(min_val, a[i]);
            min_abs = min(min_abs, abs(a[i]));
        }

        min_val = max(min_val, -min_abs);
        if (zero || cnt_minus%2 == 0) min_val = INFL;
        ll sum = 0;
        rep(i, n) {
            if (a[i] < 0) {
                if (a[i] == min_val) {
                    sum += a[i];
                    min_val = INFL;
                } else sum -= a[i];
            } else sum += a[i];
        }

        printf("%lld\n", sum);
    }
    return 0;
}