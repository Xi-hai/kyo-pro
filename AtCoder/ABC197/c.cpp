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

int main() {
    int n; scanf("%d", &n);
    VI a(n);
    rep(i, n) scanf("%d", &a[i]);

    int ans = INFI;
    rep(i, (1 << n)) {
        int itr = 0;
        VI sub_or(20);
        rep(j, n) {
            sub_or[itr] = sub_or[itr] | a[j];
            if (i & (1 << j)) itr++;
        }
        int all_xor = 0;
        rep(j, 20) all_xor = all_xor ^ sub_or[j];
        ans = min(ans, all_xor);
    }
    printf("%d\n", ans);
    return 0;
}