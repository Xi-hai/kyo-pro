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

int h, w;
vector<vector<bool>> seen(110, vector<bool>(110, false));
VI sum(110, 0);
VI dy = {1, 1, -1, -1}, dx = {1, -1, -1, 1};
void dfs(const VS &c, int y, int x) {
    int siz = 1;
    while (y+siz < h && x+siz < w && c[y+siz][x+siz] == '#') {
        siz++;
    }
    sum[siz/2]++;
    int cy = y + siz/2, cx = x + siz/2;
    rep(i, siz/2+1) {
        rep(j, 4) {
            seen[cy + dy[j] * i][cx + dx[j] * i] = true;
        }
    }
}

int main() {
    scanf("%d %d", &h, &w);
    VS c(h);
    rep(i, h) cin >> c[i];

    int n = min(h, w);
    rep(i, h) {
        rep(j, w) {
            if (c[i][j] == '#' && !seen[i][j]) {
                dfs(c, i, j);
            }
        }
    }

    rep(i, n) {
        printf(i<n-1 ? "%d " : "%d\n", sum[i+1]);
    }
    return 0;
}