//#define _GLIBCXX_DEBUG
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
    int t; //cin >> t;
    scanf("%d", &t);
    rep(s, t) {
        int n; //cin >> n;
        scanf("%d", &n);
        VI a(n);
        vector<set<int>> divisor(n);
        rep(i, n) {
            //cin >> a[i];
            scanf("%d", &a[i]);
            for (int j=2; j*j<=a[i]; j++) { //約数列挙
                if (a[i]%j==0) {
                    divisor[i].insert(j);
                    divisor[i].insert(a[i]/j);
                }
            }
            if (a[i] > 1) divisor[i].insert(a[i]);
        }

        int ans = -1;
        for (int i=n-1; i>=0; i--) {
            for (int j=i; j>=0; j--) {
                if (i+j+2 < ans) break;

                bool b = true;
                for (int p : divisor[i]) {
                    if (divisor[j].count(p)) {
                        b = false;
                        break;
                    }
                }

                if (b) ans = max(ans, i+j+2);
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}