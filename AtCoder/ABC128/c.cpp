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
    int N, M, a; cin >> N >> M;
    VI k(M), p(M);
    VVI s(M, VI(0));
    rep(i, M) {
        cin >> k[i];
        rep(j, k[i]) {
            cin >> a;
            a--;
            s[i].push_back(a);
        }
    }
    rep(i, M) cin >> p[i];

    int ans = 0;
    rep(bit, 1 << (N)) {
        VI light(M);
        rep(i, M) { //電球iは点灯するか?
            int cnt = 0;
            rep(j, k[i]) { //スイッチs[i][j]がonか?
                if (bit & (1 << (s[i][j]))) cnt++;
            }

            if (cnt % 2 == p[i]) light[i]++;
        }

        int on = 0;
        rep(i, M) {
            if (light[i]) on++;
        }
        if (on == M) ans++;
    }
    cout << ans << endl;
    return 0;
}