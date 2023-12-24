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
    vector<string> s(10);
    rep(i, 10) cin >> s[i];

    int a = INFI, b = 0, c = INFI, d = 0;
    rep(i, 10) {
        rep(j, 10) {
            if (s[i][j] == '#') {
                a = min(a, i+1);
                b = max(b, i+1);
                c = min(c, j+1);
                d = max(d, j+1);
            }
        }
    }

    printf("%d %d\n%d %d\n", a, b, c, d);
    return 0;
}