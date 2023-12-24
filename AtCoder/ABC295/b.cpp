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

int main() {
    int r, c; scanf("%d %d", &r, &c);
    VS grid(r);
    VVI bomb(10);
    rep(i, r) {
        cin >> grid[i];
        rep(j, c) {
            int num = grid[i][j] - '0';
            if (0 < num && num <= 9) {
                bomb[num].push_back(i);
                bomb[num].push_back(j);
            }
        }
    }

    rep(k, 1, 10) {
        rep(m, bomb[k].size() / 2) {
            rep(i, r) {
                rep(j, c) {
                    if (abs(i - bomb[k][2*m]) + abs(j - bomb[k][2*m+1]) <= k) {
                        grid[i][j] = '.';
                    }
                }
            }
        }
    }

    rep(i, r) cout << grid[i] << "\n";
    return 0;
}