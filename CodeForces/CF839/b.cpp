// #define _GLIBCXX_DEBUG
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
    int t; scanf("%d", &t);
    rep(t) {
        VI a(4);
        rep(i, 4) scanf("%d", &a[i]);
        swap(a[2], a[3]);
        bool b=false;
        rep(i, 4) {
            if (a[i] < a[(1+i)%4] && a[(1+i)%4] < a[(2+i)%4] &&
                a[(2+i)%4] > a[(3+i)%4] && a[(3+i)%4] > a[i]) {
                    b=true;
                    break;
                }
        }
        printf(b ? "YES\n" : "NO\n");
    }
    return 0;
}