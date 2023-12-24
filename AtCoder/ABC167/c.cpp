#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {a = b; return true;}
    return false;
}

int main() {
    int n, m, x; cin >> n >> m >> x;
    VI c(n);
    VVI acquire(n, VI(m));
    rep(i, n) {
        cin >> c[i];
        rep(j, m) cin >> acquire[i][j];
    }

    ll mincost = INFL;
    bool ans = false;
    rep(bit, (1<<n)) {
        VI comp(m, 0);
        ll cost = 0;
        rep(i, n) {
            if (((bit>>i) & 1) == 0) continue;
            cost += c[i];
            rep(j, m) {
                comp[j] += acquire[i][j];
            }
        }

        bool OK = true;
        rep(j, m) {
            if (comp[j] < x) {
                OK = false;
                break;
            }
        }
        if (OK) {
            ans = true;
            chmin(mincost, cost);
        }
    }

    if (!ans) mincost = -1;
    cout << mincost << "\n";
    return 0;
}