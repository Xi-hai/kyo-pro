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
        int n; cin >> n;
        vector<int> a(n), cnt(n+1);
        rep(i, n) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        int ans=-1;
        rep(i, n+1) {
            if (cnt[i] >= 3) {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}