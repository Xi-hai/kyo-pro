#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Graph;
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
    vector<ll> linear(N+1), square(N+1); // iの倍数の個数、i*iの倍数の個数
    rep(i, 2, N+1) {
        linear[i] = N / i;
        square[i] = N / (i*i);
        linear[i] -= square[i];
    }

    ll ans = 1;
    rep(i, 2, N+1) {
        ans += linear[i] * (linear[i]-1) / 2;
        ans += square[i] * N;
    }
    cout << ans << endl;
    return 0;
}