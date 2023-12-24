#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
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
    int N; cin >> N;
    VI a(N), b(0), cnt(0);
    map<int, int> mp; //座標圧縮
    rep(i, N) {
        cin >> a[i];
        if (mp.count(a[i])) {
            cnt[mp[a[i]]]++;
        } else {
            mp[a[i]] = b.size();
            b.push_back(a[i]);
            cnt.push_back(1);
        }
    }

    VVI v(b.size(), VI(2));
    rep(i, b.size()) {
        v[i][0] = b[i];
        v[i][1] = cnt[i];
    }

    sort(all(v), greater<vector<int>>());
    rep(i, N) {
        if (i>=b.size()) printf("0\n");
        else printf("%d\n", v[i][1]);
    }
    return 0;
}