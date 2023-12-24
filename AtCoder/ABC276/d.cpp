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
    int n; scanf("%d", &n);
    VI a(n);
    rep(i, n) scanf("%d", &a[i]);

    int sum_by2 = 0, sum_by3 = 0, min_by2 = INFI, min_by3 = INFI, ans = -1;
    bool b = true;
    rep(i, n) {
        int cnt_by2 = 0, cnt_by3 = 0;
        while (a[i]%2 == 0) {
            a[i] /= 2;
            cnt_by2++;
        }
        sum_by2 += cnt_by2;
        min_by2 = min(min_by2, cnt_by2);

        while (a[i]%3 == 0) {
            a[i] /= 3;
            cnt_by3++;
        }
        sum_by3 += cnt_by3;
        min_by3 = min(min_by3, cnt_by3);

        if (i>0 && a[i] != a[0]) {
            b = false;
            break;
        }
    }

    if (b) ans = sum_by2 + sum_by3 - n * (min_by2 + min_by3);
    printf("%d\n", ans);
    return 0;
}