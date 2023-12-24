#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

int main() {
    int t; scanf("%d", &t);
    rep(t) {
        int n; scanf("%d", &n);
        int len_b = n * (n-1) / 2;
        VI b(len_b);
        rep(i, len_b) scanf("%d", &b[i]);
        sort(all(b), greater<int>());
        VI a(1, b[0]);
        int cnt = 0;
        rep(i, len_b) {
            a.push_back(b[i]);
            i += cnt;
            cnt++;
        }
        reverse(all(a));
        rep(i, n) printf(i<n-1 ? "%d " : "%d\n", a[i]);
    }
    return 0;
}