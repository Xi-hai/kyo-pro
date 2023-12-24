#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VVI> VVVI;
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

void print_as_bin(int n) {
    string res;
    while (n>0) {
        res += (n%2 ? '1' : '0');
        n /= 2;
    }
    reverse(all(res));
    printf("%s", res.c_str());
}

int v3sum(VI &v) {
    return (v[0] + v[1] + v[2]);
}

int mex(int x, int y, int z) {
    rep(i, 3) {
        if (x != i and y != i and z != i) return i;
    }
    return 3;
}

int main() {
    int n; scanf("%d", &n);
    VI a(n);
    rep(i, n) scanf("%d", &a[i]);
    string s; cin >> s;

    VVVI mem(n, VVI(2, VI(3))); // mem[i][0]: Sのi文字目より前のM, mem[i][1]: Sのi文字目より後ろのX
    rep(i, n-1) {
        rep(j, 3) {
            mem[i+1][0][j] = mem[i][0][j] + (s[i] == 'M' && j == a[i]);
        }
    }
    rep(i, n-1) {
        rep(j, 3) {
            mem[n-2-i][1][j] = mem[n-1-i][1][j] + (s[n-1-i] == 'X' && j == a[n-1-i]);
        }
    }

    // rep(k, 2) {
    //     rep(j, 3) {
    //         rep(i, n) {
    //             printf("%d ", mem[i][k][j]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    // }

    ll ans = 0;
    rep(j, n) {
        if (s[j] != 'E') continue;
        rep(i, 3) {
            rep(k, 3) {
                ans += (ll)mem[j][0][i] * mem[j][1][k] * mex(i, a[j], k);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}