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

struct coordinate {
    int x;
    int y;
};

int n;
bool inner(int x, int y) {
    if (x<0 || n<=x || y<0 || n<=y) return false;
    return true;
}

int main() {
    int m; scanf("%d %d", &n, &m);

    VI dx(0), dy(0);
    rep(i, 1001) {
        rep(j, 1001) {
            if (i*i + j*j == m) {
                dx.push_back(i); dy.push_back(j);
                dx.push_back(-i); dy.push_back(j);
                dx.push_back(-i); dy.push_back(-j);
                dx.push_back(i); dy.push_back(-j);
            }
        }
    }
    int nv_size = dx.size();

    //BFS
    VVI dist(n, VI(n, -1));
    queue<coordinate> q;
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop();
        rep(i, nv_size) {
            rep(j, 2) {
                int nv_x = x + (j ? dx[i] : dy[i]),
                    nv_y = y + (j ? dy[i] : dx[i]);
                if (!inner(nv_x, nv_y)) continue;
                if (dist[nv_x][nv_y] != -1) continue;
                dist[nv_x][nv_y] = dist[x][y] + 1;
                q.push({nv_x, nv_y});
            }
        }
    }

    rep(i, n) rep(j, n) printf(j<n-1 ? "%d " : "%d\n", dist[i][j]);
    return 0;
}