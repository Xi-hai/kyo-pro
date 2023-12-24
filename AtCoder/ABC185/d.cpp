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
    //Not AC
    int n, m;
    cin >> n >> m;
    vector<int> a(m+2);
    rep(i, m) cin >> a[i];

    a[m] = 0;
    a[m+1] = n+1;
    sort(all(a));

    int width = INFI, dx;
    rep(i, m+1) {
        dx = a[i+1] - a[i];
        if (dx > 1 && dx < width) {
            width = dx;
        }
    }
    
    int ans = 0;
    rep(i, m+1) {
        if (a[i+1] - a[i] > 1) {
            ans += (a[i+1] - a[i]) / width;
            ans += (((a[i+1] - a[i]) % width) ? 1 : 0);
        }
    }

    cout << ans << endl;
    return 0;
}