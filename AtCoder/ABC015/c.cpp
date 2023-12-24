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
    int n, k; scanf("%d %d", &n, &k);
    VVI t(n, VI(k));
    rep(i, n) rep(j, k) scanf("%d", &t[i][j]);

    bool bug = false;
    VI val(5);
    rep(i, k) {
        val[0] = t[0][i];
        if (n>1) {
            rep(j, k) {
                val[1] = val[0] ^ t[1][j];
                if (n>2) {
                    rep(l, k) {
                        val[2] = val[1] ^ t[2][l];
                        if (n>3) {
                            rep(m, k) {
                                val[3] = val[2] ^ t[3][m];
                                if (n>4) {
                                    rep(p, k) {
                                        val[4] = val[3] ^ t[4][p];
                                        if (val[4] == 0) {
                                            bug = true;
                                            goto OUT;
                                        }
                                    }
                                }
                                else if (val[3] == 0) {
                                    bug = true;
                                    goto OUT;
                                }
                            }
                        }
                        else if (val[2] == 0) {
                            bug = true;
                            goto OUT;
                        }
                    }
                }
                else if (val[1] == 0) {
                    bug = true;
                    goto OUT;
                }
            }
        }
        else if (val[0] == 0) {
            bug = true;
            goto OUT;
        }
    }

    OUT:
    printf(bug ? "Found\n" : "Nothing\n");
    return 0;
}