#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

int main() {
    int n, k; cin >> n >> k;
    VVI points(n, VI(2));
    rep(i, n) cin >> points[i][0] >> points[i][1];

    set<tuple<ll, ll, ll>> lines;
    rep(i, n) {
        rep(j, i+1, n) {
            ll b = points[i][0] - points[j][0];
            ll a = points[j][1] - points[i][1];
            ll c = - a*points[i][0] - b*points[i][1];
            ll GCD = __gcd(a, __gcd(b, c));
            a /= GCD; b /= GCD; c /= GCD;
            if (a<0) {a*=-1; b*=-1; c*=-1;}
            lines.insert( {a, b, c} );
        }
    }

    int ans = 0, idx = 0;
    VI cnt;
    if (k==1) {
        cout << "Infinity\n";
        return 0;
    }
    for (auto t : lines) {
        cnt.push_back(0);
        ll a, b, c;
        tie(a, b, c) = t;
        rep(i, n) {
            if (a*points[i][0] + b*points[i][1] + c == 0) cnt[idx]++;
        }
        
        if (cnt[idx] >= k) ans++;
        idx++;
    }
    cout << ans << "\n";
    return 0;
}