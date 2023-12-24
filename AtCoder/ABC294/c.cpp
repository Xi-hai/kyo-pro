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
    // int n, m; scanf("%d %d", &n, &m);
    // VI a(n), b(m);
    // map<int, int> mp_a, mp_b;
    // set<int> st;
    // rep(i, n) {
    //     scanf("%d", &a[i]);
    //     mp_a[a[i]] = i;
    //     st.insert(a[i]);
    // }
    // rep(i, m) {
    //     scanf("%d", &b[i]);
    //     mp_b[b[i]] = i;
    //     st.insert(b[i]);
    // }

    // VI itr_a(n), itr_b(m);
    // int i = 1;
    // for (int t : st) {
    //     if (mp_a.count(t)) {
    //         itr_a[mp_a[t]] = i;
    //     } else {
    //         itr_b[mp_b[t]] = i;
    //     }
    //     i++;
    // }
    // rep(i, n) {
    //     printf(i<n-1 ? "%d " : "%d\n", itr_a[i]);
    // }
    // rep(i, m) {
    //     printf(i<m-1 ? "%d " : "%d\n", itr_b[i]);
    // }

    int n, m; scanf("%d %d", &n, &m);
    VI a(n), b(m), c;
    rep(i, n) scanf("%d", &a[i]);
    rep(i, m) scanf("%d", &b[i]);
    merge(all(a), all(b), back_inserter(c));

    rep(i, n) {
        int ans = lower_bound(all(c), a[i]) - c.begin();
        printf(i<n-1 ? "%d " : "%d\n", ans+1);
    }
    rep(j, m) {
        int ans = lower_bound(all(c), b[j]) - c.begin();
        printf(j<m-1 ? "%d " : "%d\n", ans+1);
    }
    return 0;
}