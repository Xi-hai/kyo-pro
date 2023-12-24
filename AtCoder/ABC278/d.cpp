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
    int n, q; scanf("%d", &n);
    VVL a(n+1, VL(2));
    rep(j, n) scanf("%lld", &a[j+1][0]);
    scanf("%d", &q);
    int t, i, layer=0;
    ll x, now_x=0;
    rep(q) {
        scanf("%d", &t);

        if (t==1) {
            scanf("%lld", &x);
            now_x = x;
            layer++;
        } else if (t==2) {
            scanf("%d %lld", &i, &x);
            if (a[i][1] < layer) {
                a[i][0] = x;
                a[i][1] = layer;
            } else {
                a[i][0] += x;
            }
        } else {
            scanf("%d", &i);
            if (a[i][1] < layer) {
                printf("%lld\n", now_x);
            } else {
                printf("%lld\n", now_x + a[i][0]);
            }
        }
    }
    return 0;
}