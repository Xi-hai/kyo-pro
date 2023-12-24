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
const VI dy = {0, 1, 0, -1};
const VI dx = {1, 0, -1, 0};
const VI dy8 = {0, 1, 1, 1, 0, -1, -1, -1};
const VI dx8 = {1, 1, 0, -1, -1, -1, 0, 1};

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {a = b; return true;}
    return false;
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {a = b; return true;}
    return false;
}

void print_as_bin(int n) {
    string res;
    while (n>0) {
        res += (n%2 ? '1' : '0');
        n /= 2;
    }
    reverse(all(res));
    printf("%s", res.c_str());
}

int main() {
    int h, w; cin >> h >> w;
    VS color(h);
    rep(i, h) cin >> color[i];

    VVI row(h, VI(26)), col(w, VI(26));
    rep(i, h) {
        rep(j, w) {
            row[i][color[i][j] - 'a']++;
            col[j][color[i][j] - 'a']++;
        }
    }

    // ここから解説コピペ
    int nh = h, nw = w;
    vector<bool> fx(h, false), fy(w, false);
    rep(h+w) {
        vector<pair<int, int>> ux, uy;
        rep(i, h) {
            if (fx[i]) continue;
            rep(c, 26) {
                if (row[i][c] == nw && nw >= 2) {
                    ux.push_back({i, c});
                }
            }
        }
        rep(j, w) {
            if (fy[j]) continue;
            rep(c, 26) {
                if (col[j][c] == nh && nh >= 2) {
                    uy.push_back({j, c});
                }
            }
        }

        for (auto p : ux) {
            fx[p.first] = true;
            rep(j, w) col[j][p.second]--;
            nh--;
        }
        for (auto p : uy) {
            fy[p.first] = true;
            rep(i, h) row[i][p.second]--;
            nw--;
        }
    }

    cout << nh * nw << "\n";
    return 0;
}