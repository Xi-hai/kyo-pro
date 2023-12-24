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
    VI a(n), a_sorted(n+1);
    rep(i, n) {
        scanf("%d", &a[i]);
        a_sorted[i] = a[i];
    }
    a_sorted[n] = 1010101010;
    sort(all(a_sorted));

    int rank = 0;
    unordered_map<int, int> mp;
    rep(i, n) {
        if (a_sorted[i] != a_sorted[i+1]) {
            mp[a_sorted[i]] = rank;
            rank++;
        }
    }

    rep(i, n) printf("%d\n", mp[a[i]]);
    return 0;
}