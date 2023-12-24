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

int h, w;
string snuke = "snuke";
void dfs(const VS &grid, VVI &dist, int v_i, int v_j) {
    rep(u, 4) {
        int nv_i = v_i + dy[u], nv_j = v_j + dx[u];
        if (nv_i < 0 || nv_i >= h || nv_j < 0 || nv_j >= w) continue;
        rep(v, 5) {
            if ((dist[v_i][v_j] >> v) == 1 && grid[nv_i][nv_j] == snuke[(v+1)%5]) {
                if (dist[nv_i][nv_j] >> ((v+1) % 5) == 1) continue;
                dist[nv_i][nv_j] |= (1 << ((v+1) % 5));
                dfs(grid, dist, nv_i, nv_j);
            }
        }
    }
}

int main() {
    scanf("%d %d", &h, &w);
    VS grid(h);
    rep(i, h) cin >> grid[i];
    VVI dist(h, VI(w));
    dist[0][0] = 1;
    dfs(grid, dist, 0, 0);
    printf(dist[h-1][w-1] > 0 ? "Yes\n" : "No\n");
    return 0;
}