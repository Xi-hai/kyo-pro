#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
typedef vector<vector<int>> Graph;

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

int main() {
    int n, a, idx=0; cin >> n;
    vector<int> cnt(0);
    map<int, int> idx_convert;
    rep(i, n) {
        cin >> a;
        if (idx_convert.count(a)) {
            cnt[idx_convert[a]]++;
        } else {
            cnt.push_back(1);
            idx_convert[a] = idx;
            idx++;
        }
    }

    int L = cnt.size();
    ll ans = 1;
    rep(i, 3) {
        ans *= n-i;
        ans /= i+1;
    }

    rep(i, L) {
        ans -= (ll)cnt[i] * (cnt[i]-1) / 2 * (n - cnt[i]);
        ans -= (ll)cnt[i] * (cnt[i]-1) / 2 * (cnt[i] -2) / 3;
    }
    cout << ans << endl;
    return 0;
}