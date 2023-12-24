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
        int n, zero=0, ans; cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        set<int> cnt;
        bool equal = false;

        rep(i, n) {
            if (a[i] == 0) zero++;
            if (cnt.count(a[i])) equal = true;
            else cnt.insert(a[i]);
        }

        if (zero) {
            ans = n - zero;
        } else if (equal) {
            ans = n;
        } else {
            ans = n+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}