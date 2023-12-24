#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()
typedef vector<vector<int>> Graph;

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

//15AC, 16WA
int main() {
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> a(N), sum(N+1);
    rep(i, N) cin >> a[i];
    rep(i, N) sum[i+1] = sum[i] + a[i];

    map<ll, ll> mp;
    ll ans=0;
    rep(r, 1, N+1) {
        mp[sum[r-1]]++;
        ans += mp[sum[r] - K];
    }

    cout << ans << endl;
    return 0;
}