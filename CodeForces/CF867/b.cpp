#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> VL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

const int INFI = 1 << 30;

int main() {
    int t; scanf("%d", &t);
    rep(t) {
        int n; scanf("%d", &n);
        VL a(n);
        rep(i, n) scanf("%lld", &a[i]);

        VL maximum(3, -INFI), minimum(3, INFI);
        rep(i, n) {
            maximum[2] = a[i];
            minimum[2] = a[i];
            sort(all(maximum), greater<ll>());
            sort(all(minimum));
        }

        ll ans = max(maximum[0] * maximum[1], minimum[0] * minimum[1]);
        printf("%lld\n", ans);
    }
    return 0;
}