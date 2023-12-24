#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> Graph;
typedef vector<VI> DPI;
typedef vector<VL> DPL;
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
    int n, p=0;
    cin >> n;
    vector<int> a(n), base(4);
    rep(i, n) cin >> a[i];

    rep(i, n) {
        base[0] = 1;
        rep(j, 4) {
            if (base[3-j]) {
                base[3-j] = 0;
                if (3-j + a[i] > 3) p++;
                else base[3-j + a[i]]++;
            }
        }
    }
    cout << p << endl;
    return 0;
}