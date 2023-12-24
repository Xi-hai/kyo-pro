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
        char c = ' ';
        rep(i, n) {
            if (c == ' ') {
                printf("%c", s[i]);
                c = s[i];
            }
            else if (s[i] == c) {
                c = ' ';
            }
        }
        printf("\n");
    }
    return 0;
}