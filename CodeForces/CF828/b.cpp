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
    int t; cin >> t;
    rep(t) {
        int n, q; cin >> n >> q;
        VL a(n);
        int count_even = 0, count_odd = 0;
        ll sum = 0;
        rep(i, n) {
            cin >> a[i];
            sum += a[i];
            if (a[i]%2) count_odd++;
            else count_even++;
        }

        int type;
        ll x;
        rep(q) {
            cin >> type >> x;
            if (type) {
                sum += x * count_odd;
                if (x%2) {
                    count_even += count_odd;
                    count_odd = 0;
                }
            } else {
                sum += x * count_even;
                if (x%2) {
                    count_odd += count_even;
                    count_even = 0;
                }
            }
            printf("%lld\n", sum);
        }
    }
    return 0;
}