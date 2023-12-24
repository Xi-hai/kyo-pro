#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
typedef vector<vector<int>> Graph;

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

int main() {
    int t; cin >> t;
    rep(test, t) {
        int x, y; cin >> x >> y;

        if (y/x == 0 || y%x > 0) {
            printf("0 0\n");
            continue;
        }
        if (x == y) {
            printf("1 1\n");
            continue;
        }
        y /= x;

        printf("1 %d\n", y);
    }
    return 0;
}