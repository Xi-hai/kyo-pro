//#define _GLIBCXX_DEBUG
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
        ll l, r, x, a, b;
        scanf("%lld %lld %lld\n%lld %lld", &l, &r, &x, &a, &b);
        ll ans = -1;
        ll a_l=a-x, a_r=a+x, b_l=b-x, b_r=b+x;

        if (a == b) ans = 0;

        else if (abs(a-b) >= x) ans = 1;

        else if ((a_l < l && r < a_r) || (b_l < l && r < b_r)) ans = -1;

        else if ((l <= a_l && l <= b_l) || (a_r <= r && b_r <= r)) ans = 2;

        else if (abs(l-r) >= x && ((l <= a_l && b_r <= r) || (l <= b_l && a_r <= r))) ans = 3;

        printf("%lld\n", ans);
    }
    return 0;
}