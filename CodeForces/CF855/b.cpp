#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

int main() {
    int t; scanf("%d", &t);
    rep(t) {
        int n, k; scanf("%d %d", &n, &k);
        string s; cin >> s;
        VI lower(26), upper(26);
        rep(i, n) {
            if (s[i] - 'a' >= 0) lower[s[i] - 'a']++;
            else upper[s[i] - 'A']++;
        }

        int ans = 0, op = 0;
        rep(i, 26) {
            ans += min(lower[i], upper[i]);
            op += abs(lower[i] - upper[i]) / 2;
        }

        ans += min(op, k);
        printf("%d\n", ans);
    }
    return 0;
}