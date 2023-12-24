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
    int t; cin >> t;
    rep(t) {
        int n, div2_a = 0; cin >> n;
        VI a(n), div2_i(20);
        rep(i, n) {
            cin >> a[i];
            int x = a[i];
            while (x % 2 == 0) {
                x /= 2;
                div2_a++;
            }

            int y = i+1, div2_itr = 0;
            while (y % 2 == 0) {
                y /= 2;
                div2_itr++;
            }
            div2_i[div2_itr]++;
        }
        
        int ans = 0;
        n -= div2_a;
        if (n <= 0) goto OUT;
        for (int i=19; i>0; i--) {
            while (div2_i[i]) {
                n -= i;
                div2_i[i]--;
                ans++;
                if (n <= 0) goto OUT;
            }
        }

        if (n>0) ans = -1;
        OUT:
        printf("%d\n", ans);
    }
    return 0;
}