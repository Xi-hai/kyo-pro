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
const ll INFL = 1LL << 58;

int main() {
    ll x; scanf("%lld", &x);
    VL mem;
    ll tp = x;
    while (tp/10 > 0) tp /= 10;
    rep(i, 10) {
        mem.push_back(i);
        rep(j, -9, 10) {
            ll d = i, num = i;
            ll p = 10;
            if (d == 0 && j == 0) break;
            while (0 <= d && d <= 9 && num < INFL) {
                num = num*10 + d;
                if (num > 100) {
                    mem.push_back(num - (ll)i * p);
                }
                d += j;
                p *= 10LL;
            }
        }
    }

    sort(all(mem));
    mem.erase(unique(all(mem)), mem.end());
    ll ans = lower_bound(all(mem), x) - mem.begin();
    cout << mem[ans] << "\n";
    return 0;
}