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

int h, w, ans;
vector<vector<bool>> seen;
map<int, int> mp;
void dfs(const VVI &grid, int i, int j) {
    //行きがけ
    seen[i][j] = true;
    mp[grid[i][j]]++;

    if (i==h-1 && j==w-1) {
        if (mp.size() == h+w-1) ans++;
        return;
    }

    if (i<h-1) dfs(grid, i+1, j);
    if (j<w-1) dfs(grid, i, j+1);
    
    //帰りがけ
    mp[grid[i][j]]--;
    if (mp[grid[i][j]] == 0) mp.erase(grid[i][j]);
}

int main() {
    scanf("%d %d", &h, &w);
    ans = 0;
    seen.assign(h, vector<bool>(w, false));
    mp.clear();
    VVI a(h, VI(w));
    rep(i, h) rep(j, w) scanf("%d", &a[i][j]);
    dfs(a, 0, 0);
    printf("%d\n", ans);
    return 0;
}