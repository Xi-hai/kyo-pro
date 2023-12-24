#include <bits/stdc++.h>
using namespace std;
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
        VI a(n), even, odd;
        rep(i, n) {
            scanf("%d", &a[i]);
            if (a[i] % 2) odd.push_back(a[i]);
            else even.push_back(a[i]);
        }
        sort(all(odd));
        sort(all(even));

        int len_odd = odd.size(), len_even = even.size();
        bool ans = false;
        if (len_even == 0) {
            ans = true;
        }
        else if (len_odd == 0) {
            ans = true;
        }

        else if (len_even == 1) {
            if (odd[len_even-1] < even[0]) ans = true;
        }
        else if (len_odd == 1) {
            if (odd[0] < even[0]) ans = true;
        }

        else if (odd[0] < even[0]) ans = true;

        printf(ans ? "Yes\n" : "No\n");
    }
    return 0;
}