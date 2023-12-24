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
    VI h(3), w(3);
    rep(i, 3) cin >> h[i];
    rep(i, 3) cin >> w[i];
    VVI grid(3, VI(3));
    int ans=0;

    rep(i, 1, 31) { //(0,0)
        if (i > min(h[0], w[0])) continue;
        grid[0][0] = i;

        rep(j, 1, 31) { //(0,1)
            if (j > min(h[0], w[1])) continue;
            grid[0][1] = j;

            rep(k, 1, 31) { //(1,0)
                if (k > min(h[1], w[0])) continue;
                grid[1][0] = k;

                rep(l, 1, 31) { //(1,1)
                    if (l > min(h[1], w[1])) continue;
                    grid[1][1] = l;

                    grid[0][2] = h[0] - grid[0][0] - grid[0][1];
                    grid[1][2] = h[1] - grid[1][0] - grid[1][1];
                    grid[2][0] = w[0] - grid[0][0] - grid[1][0];
                    grid[2][1] = w[1] - grid[0][1] - grid[1][1];
                    grid[2][2] = h[2] - grid[2][0] - grid[2][1];

                    if (grid[0][2] < 1 || grid[1][2] < 1 || grid[2][0] < 1 || grid[2][1] < 1 || grid[2][2] < 1) {
                        continue;
                    }

                    if (grid[0][2] + grid[1][2] + grid[2][2] == w[2]) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}