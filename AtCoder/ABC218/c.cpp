#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Graph;
typedef vector<vector<int>> DPI;
typedef vector<vector<ll>> DPL;
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

vector<string> s(200);
int N;

//平行移動して一致するか調べる
bool judge(vector<string> &t) {
    bool ret = true;
    rep(p, N) { //縦方向のずれ
        rep(q, N) { //横方向のずれ
            ret = true;
            rep(i, N) {
                rep(j, N) {
                    if (s[i][j] != t[(i+p) % N][(j+q) % N]) {
                        ret = false;
                    }
                }
            }
            if (ret) return true;
        }
    }
    return false;
}

int main() {
    cin >> N;
    s = vector<string>(N);
    vector<string> t(N);
    rep(i, N) cin >> s[i];
    rep(i, N) cin >> t[i];

    rep(k, 4) {
        if (judge(t)) {
        cout << "Yes\n";
        return 0;
        }

        if (k<3) {
            vector<string> rot(N);
            rep(i, N) rep(j, N) rot[i] += ".";
            rep(i, N) {
                rep(j, N) {
                    rot[i][j] = t[N-1-j][i];
                }
            }
            t = rot;
        }
    }

    cout << "No\n";
    return 0;
}