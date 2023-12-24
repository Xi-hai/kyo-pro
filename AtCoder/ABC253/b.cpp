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
    int H, W; cin >> H >> W;
    vector<string> s(H);
    rep(i, H) cin >> s[i];

    int x1, x2, y1, y2;
    bool p1 = true;
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == 'o') {
                if (p1) {
                    x1 = j;
                    y1 = i;
                    p1 = false;
                } else {
                    x2 = j;
                    y2 = i;
                    goto OUT;
                }
            }
        }
    }

    OUT:
    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    return 0;
}