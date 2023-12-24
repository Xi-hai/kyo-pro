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
    int N, M; cin >> N >> M;
    VI k(M);
    VVI x(M, VI(0));
    rep(i, M) {
        cin >> k[i];
        x[i] = VI(k[i]);
        rep(j, k[i]) {
            cin >> x[i][j];
            x[i][j]--;
        }
    }

    VVI p(N, VI(N, 0));
    rep(i, M) {
        rep(j, k[i]) {
            rep(l, j+1, k[i]) {
                p[x[i][j]][x[i][l]]++;
                p[x[i][l]][x[i][j]]++;
            }
        }
    }

    rep(i, N) {
        rep(j, N) {
            if (i!=j && p[i][j]==0) goto NO;
        }
    }
    cout << "Yes\n";
    return 0;

    NO:
    cout << "No\n";
    return 0;
}