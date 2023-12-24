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

int main() {
    int n, m; cin >> n >> m;
    VL a(n);
    ll sum=0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a));

    // int x=a[0];
    ll sub_sum=a[0], ans=sum;
    bool b=true;
    rep(i, 2*n+2) {
        if (a[(i+1)%n] == a[i%n] || a[(i+1)%n] == (a[i%n]+1)%m) {
            sub_sum += a[(i+1)%n];
        } else {
            b=false;
            ans = min(ans, sum - sub_sum);
            sub_sum = a[(i+1)%n];
        }
    }

    if (b) ans = 0;
    if (n==1) ans=0;
    printf("%lld\n", ans);
    return 0;
}