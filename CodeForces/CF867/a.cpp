#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {a = b; return true;}
    return false;
}

int main() {
    int q; scanf("%d", &q);
    rep(q) {
        int n, t; scanf("%d %d", &n, &t);
        VI a(n), b(n);
        rep(i, n) scanf("%d", &a[i]);
        rep(i, n) scanf("%d", &b[i]);

        int ans_idx = -1, ans_val = 0;
        rep(i, n) {
            if (a[i] + i <= t) {
                if (chmax(ans_val, b[i])) ans_idx = i+1;
            }
        }

        printf("%d\n", ans_idx);
    }
    return 0;
}