#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Graph;
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
    int H, W; cin >> H >> W;
    vector<string> maze(H);
    rep(i, H) cin >> maze[i];

    Graph count(H, vector<int>(W));
    count[0][0] = 1;
    rep(i, H) {
        rep(j, W) {
            if (maze[i][j] == '#') continue;;

            if (j>0 && count[i][j-1]) count[i][j] = count[i][j-1]+1;
            if (i>0 && count[i-1][j]) count[i][j] = count[i-1][j]+1;
        }
    }

    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            ans = max(ans, count[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}