#include <bits/stdc++.h>
using namespace std;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {a = b; return true;}
    return false;
}

int main() {
    int t; scanf("%d", &t);
    rep(t) {
        int n, k; scanf("%d %d", &n, &k);
        int ans = n+1;
        if (k < 30) {
            chmin(ans, (1 << k));
        }
        printf("%d\n", ans);
    }
    return 0;
}