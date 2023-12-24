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
    ll N; cin >> N;

    //Nの2進数表記の1の個数と位置を数える
    int count_1=0;
    vector<ll> posi(0);
    for (int i=0; (i<60 && N>0); i++) {
        if (N%2) {
            posi.push_back(i);
            count_1++;
        }
        N/=2;
    }

    rep(i, (1 << count_1)) {
        ll ans=0;
        rep(j, count_1) {
            if (i & (1 << j)) {
                ans += (1LL << posi[j]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}