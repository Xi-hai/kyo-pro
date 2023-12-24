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
    VI v(n);
    rep(i, n) cin >> v[i];
    VI even_cnt(1e5+1), odd_cnt(1e5+1);
    rep(i, n) {
        if (i%2) odd_cnt[v[i]]++;
        else even_cnt[v[i]]++;
    }
    VI even_num(2), odd_num(2);
    rep(i, 1, 1e5+1) {
        if (even_cnt[i] >= even_cnt[even_num[0]]) {
            even_num[1] = even_num[0];
            even_num[0] = i;
        }
        else if (even_cnt[i] >= even_cnt[even_num[1]]) {
            even_num[1] = i;
        }

        if (odd_cnt[i] >= odd_cnt[odd_num[0]]) {
            odd_num[1] = odd_num[0];
            odd_num[0] = i;
        }
        else if (odd_cnt[i] >= odd_cnt[odd_num[1]]) {
            odd_num[1] = i;
        }
    }

    int ans = n;
    if (even_num[0] != odd_num[0]) {
        ans = n - even_cnt[even_num[0]] - odd_cnt[odd_num[0]];
    } else {
        ans = min(n - even_cnt[even_num[0]] - odd_cnt[odd_num[1]],
                  n - even_cnt[even_num[1]] - odd_cnt[odd_num[0]]);
    }
    cout << ans << "\n";
    return 0;
}