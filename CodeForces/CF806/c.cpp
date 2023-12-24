#define _GLIBCXX_DEBUG
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
    int t; cin >> t;
    rep(i, t) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        vector<string> s(n);
        rep(j, n) cin >> a[j];
        rep(j, n) {
            cin >> b[j] >> s[j];
            rep(k, b[j]) {
                if (s[j][k] == 'U') a[j]--;
                else a[j]++;
            }
            a[j] %= 10;
            if (a[j] < 0) a[j] += 10;
        }

        rep(j, n-1) {
            printf("%d ", a[j]);
        }
        printf("%d\n", a[n-1]);
    }
    return 0;
}