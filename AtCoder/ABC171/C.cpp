#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

int main() {
    ll N;
    string ans;
    cin >> N;
    while (N>0) {
        ans += (char)('a' + (N-1) % 26LL);
        N = (N-1) / 26LL;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}