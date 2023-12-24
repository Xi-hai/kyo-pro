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
    VI a(N), even(0), odd(0);
    rep(i, N) {
        cin >> a[i];
        if (a[i]%2) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }

    int ans=-1;
    if ((int)even.size() > 1) {
        sort(all(even), greater<int>());
        ans = max(ans, even[0]+even[1]);
    }
    if ((int)odd.size() > 1) {
        sort(all(odd), greater<int>());
        ans = max(ans, odd[0]+odd[1]);
    }
    cout << ans << endl;
    return 0;
}