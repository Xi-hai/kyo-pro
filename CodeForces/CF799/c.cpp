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
    int t; scanf("%d", &t);
    rep(t) {
        VS s(8);
        rep(i, 8) cin >> s[i];

        int sum = -1, sub = 10;
        bool b = true;
        rep(j, 8) {
            if (s[0][j] == '#') {
                if (b) sub = -j;
                else sum = j;
                b = !b;
            }
        }

        if (!b) {
            b = true;
            rep(i, 8) {
                if (s[i][0] == '#') {
                    if (b) sub = i;
                    else sum = i;
                    b = !b;
                }
            }
        }

        rep(i, 8) {
            rep(j, 8) {
                if (i+j == sum && i-j == sub) {
                    printf("%d %d\n", i+1, j+1);
                    goto OUT;
                }
            }
        }

        OUT:
        b = !b;
    }
    return 0;
}