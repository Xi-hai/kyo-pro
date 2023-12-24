#define _GLIBCXX_DEBUG
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
#define all(obj) (obj).begin(), (obj).end()

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {a = b; return true;}
    return false;
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {a = b; return true;}
    return false;
}

int main() {
    int n; scanf("%d", &n);
    VL a(n); rep(i, n) scanf("%lld", &a[i]);
    VS s(n); rep(i, n) cin >> s[i];
    VVI dist(n, VI(n, 10000));
    VVL valsum(n, VL(n, 0LL));
    rep(i, n) {
        rep(j, n) {
            if (s[i][j] == 'Y') {
                dist[i][j] = 1;
                valsum[i][j] = a[i] + a[j];
            }
        }
    }

    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                if (chmin(dist[i][j], dist[i][k] + dist[k][j])) {
                    valsum[i][j] = valsum[i][k] + valsum[k][j] - a[k];
                } else if (dist[i][k] + dist[k][j] > dist[i][j]) {
                    continue;
                } else {
                    chmax(valsum[i][j], valsum[i][k] + valsum[k][j] - a[k]);
                }
            }
        }
    }

    int q; scanf("%d", &q);
    rep(q) {
        int u, v; scanf("%d %d", &u, &v);
        u--, v--;
        printf(dist[u][v] < 10000 ? "%d %lld\n" : "Impossible\n",
                dist[u][v], valsum[u][v]);
    }
    return 0;
}