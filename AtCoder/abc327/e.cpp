#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
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
const VI dy = {0, 1, 0, -1};
const VI dx = {1, 0, -1, 0};
const VI dy8 = {0, 1, 1, 1, 0, -1, -1, -1};
const VI dx8 = {1, 1, 0, -1, -1, -1, 0, 1};

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
    int n; cin >> n;
    VI p(n+1); rep(i, 1, n+1) cin >> p[i];

    VV<long double> dp(n+1, V<long double>(n+1, -INFI));
    V<long double> a(n+1);
    a[1] = 0.1;
    rep(i, 1, n+1) {
        dp[1][i] = p[i];
        if (i==n) break;
        a[i+1] = 0.9*a[i] + 0.1;
    }

    rep(k, 1, n) {
        long double M = dp[k][1];
        rep(j, 1, k+1) {
            chmax(M, dp[k][j]);
        }
        rep(j, k+1, n+1) {
            dp[k+1][j] = M*0.9 + p[j];
            chmax(M, dp[k][j]);
        }
    }

    long double ans = -INFI;
    rep(k, 1, n+1) {
        rep(j, 1, n+1) {
            printf("%10Lg, ", dp[k][j]);
        }
        printf("\n");
        chmax(ans, 0.1*dp[k][n]/a[k] - 1200/sqrt(k));
    }

    printf("%.10Lf\n", ans);
    return 0;
}