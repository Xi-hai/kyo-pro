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
    int n, t; scanf("%d %d", &n, &t);
    VI c(n), r(n);
    rep(i, n) scanf("%d", &c[i]);
    rep(i, n) scanf("%d", &r[i]);

    unordered_map<int, int> mp, col;
    int m = 0;
    vector<set<int>> v;
    rep(i, n) mp[r[i]] = i+1;
    rep(i, n) {
        if (!col.count(c[i])) {
            col[c[i]] = m;
            m++;
            v.push_back({r[i]});
        } else {
            v[col[c[i]]].insert(r[i]);
        }
    }

    if (!col.count(t)) t = c[0];
    printf("%d\n", mp[*v[col[t]].rbegin()]);
    return 0;
}