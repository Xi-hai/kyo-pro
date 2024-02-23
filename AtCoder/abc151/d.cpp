#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

const int INFI = 1 << 30;
const VI dy = {0, 1, 0, -1};
const VI dx = {1, 0, -1, 0};

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

int bfs(const int H, const int W, VV<char>& grid, const int sh, const int sw) {
    VVI dist(H, VI(W, INFI));
    dist[sh][sw] = 0;
    queue<pair<int, int>> q;
    q.push({sh, sw});
    int dist_max = 0;

    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();

        chmax(dist_max, dist[i][j]);

        rep(k, 4) {
            int ni = i + dy[k], nj = j + dx[k];
            if (ni<0 || H<=ni || nj<0 || W<=nj || grid[ni][nj] == '#') {
                continue;
            }
            if (chmin(dist[ni][nj], dist[i][j]+1)) {
                q.push({ni, nj});
            }
        }
    }
    return dist_max;
}

int main() {
    int H, W; cin >> H >> W;
    VV<char> grid(H, V<char>(W));
    rep(i, H) rep(j, W) cin >> grid[i][j];

    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (grid[i][j] == '#') continue;
            chmax(ans, bfs(H, W, grid, i, j));
        }
    }
    cout << ans << "\n";
    return 0;
}