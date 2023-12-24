#include <bits/stdc++.h>
using namespace std;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

int main() {
    int t; scanf("%d", &t);
    rep(t) {
        int n; scanf("%d", &n);
        string s; cin >> s;
        set<int> st;
        rep(i, n-1) {
            int v = (s[i] - 'a') * 8 + (s[i+1] - 'a');
            st.insert(v);
        }
        printf("%ld\n", st.size());
    }
    return 0;
}