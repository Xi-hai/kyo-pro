#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
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
    VVI a(2*n, VI(2*n));
    rep(i, 2*n) {
        rep(j, i+1, 2*n) {
            cin >> a[i][j];
        }
    }
    // 全パターンは (2*n)! / (n! * 2^n) ~ 2 * 10^6 通り

    // next_permutationを(2*n)回まわすことになりTLEする
    set<vector<PII>> checked;
    VI perm(2*n);
    rep(i, 2*n) perm[i] = i;
    int ans = 0;
    do {
        bool used = false;
        rep(i, n) {
            if (perm[2*i] > perm[2*i + 1]) {
                used = true;
                break;
            }
        }
        if (used) continue;

        vector<PII> sorted(n);
        rep(i, n) {
            sorted[i] = {perm[2*i], perm[2*i + 1]};
        }
        sort(all(sorted));
        if (checked.count(sorted)) continue;
        checked.insert(sorted);

        int fun = 0;
        rep(i, n) {
            fun ^= a[ perm[2*i] ][ perm[2*i + 1] ];
        }
        chmax(ans, fun);
    } while (next_permutation(all(perm)));

    cout << ans << "\n";
    return 0;
}