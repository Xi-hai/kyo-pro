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

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {a = b; return true;}
    return false;
}

int main() {
    ll n, ans = 1e18; cin >> n;
    // 対称性から a >= b とおける
    // x = a^3 + (a^2)*b + a*(b^2) + b^3
    //   = (a^2 + b^2)*(a + b)
    //   = ( (a+b)^2 + (a-b)^2 )*(a+b) / 2
    //  >= (a+b)^3 / 2
    //  >= 4*b^3

    for (ll b=cbrt(n/4); b<=700000; b++) {
        for (ll a=b; (a*a + b*b)*(a+b) <= INFL; a++) {
            ll x = (a*a + b*b) * (a+b);
            if (n > x) continue;
            if (chmin(ans, x)) break;
        }
    }
    // 制約とsample2から x <= 10^18
    OUT:
    cout << ans << "\n";
    return 0;
}