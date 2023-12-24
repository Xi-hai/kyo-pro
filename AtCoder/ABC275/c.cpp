#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

int main() {
    vector<string> s(9);
    rep(i, 9) cin >> s[i];
    
    int ans=0;
    rep(i1, 8) {
        rep(j1, 8) {
            if (s[i1][j1] == '.') continue;
            rep(i2, i1, 9) {
                rep(j2, j1+1, 9) {
                    if (s[i2][j2] == '.') continue;
                    int di = i2 - i1;
                    int dj = j2 - j1;
                    int i3 = i2 + dj;
                    int j3 = j2 - di;
                    int i4 = i3 - di;
                    int j4 = j3 - dj;
                    if (8<i3 || j3<0 || s[i3][j3] == '.') continue;
                    if (i4<0 || 8<i4 || j4<0 || 8<j4 || s[i4][j4] == '.') continue;
                    // printf("(%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", i1+1, j1+1, i2+1, j2+1, i3+1, j3+1, i4+1, j4+1);
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}