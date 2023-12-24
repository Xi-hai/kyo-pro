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
    int n, m; cin >> n >> m;
    VI price(n);
    rep(i, n) cin >> price[i];
    vector<pair<int, int>> voucher(m);
    rep(i, m) cin >> voucher[i].first;
    rep(i, m) {
        cin >> voucher[i].second;
        // voucher[i].second *= -1;
    }

    sort(all(price), greater<int>());
    sort(all(voucher), greater<pair<int, int>>());
    int i=0, j=0;
    while (i<n && j<m) {
        if (price[i] < voucher[j].first) {
            j++;
            continue;
        }
        price[i] -= voucher[j].second;
        i++, j++;
    }

    ll ans = 0;
    rep(i, n) ans += price[i];
    cout << ans << "\n";
    return 0;
}