//#define _GLIBCXX_DEBUG
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
    int t; cin >> t;
    rep(t) {
        ll n, m; cin >> n >> m;
        ll ans = n;

        int div2_n=0, div5_n=0;
        while (n % 2LL == 0LL) {
            n /= 2LL;
            div2_n++;
        }
        while (n % 5LL == 0LL) {
            n /= 5LL;
            div5_n++;
        }

        ll k=1;
        while (k<m) {
            if (div2_n < div5_n) {
                k *= 2LL;
                div2_n++;
            }
            else if (div5_n < div2_n) {
                k *= 5LL;
                div5_n++;
            }
            else {
                k *= 10LL;
                div2_n++;
                div5_n++;
            }
        }

        if (div2_n >= div5_n && k%2LL == 0LL) {
            k /= 2LL;
            div2_n--;
        }
        if (div5_n >= div2_n && k%5LL == 0LL) {
            k /= 5LL;
            div5_n--;
        }
        if (ans * m < 10) k=m;

        printf("ans=%lld\n", ans*k);
    }
    return 0;
}