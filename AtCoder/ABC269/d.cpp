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

VI dx = {-1, -1, 0, 0, 1, 1};
VI dy = {-1, 0, -1, 1, 0, 1};

int main() {
    VVI grid(2003, VI(2003, -1)); //-1:白, 0:黒(未探索), i(>0):黒(探索済み)
    int N; cin >> N;
    VI x(N), y(N);
    rep(i, N) {
        cin >> x[i] >> y[i];
        x[i] += 1001;
        y[i] += 1001;
        grid[x[i]][y[i]] = 0;
    }

    //BFS
    queue<int> que_x, que_y;
    //vector<vector<bool>> seen(2001, vector<bool>(2001, false));
    int memo = 1;

    rep(i, 1, 2002) {
        rep(j, 1, 2002) {
            if (grid[i][j] != 0) continue;
            que_x.push(i);
            que_y.push(j);
            grid[i][j] = memo;
            while (!que_x.empty()) {
                int v_x = que_x.front(); que_x.pop();
                int v_y = que_y.front(); que_y.pop();
                rep(k, 6) {
                    int nv_x = v_x + dx[k];
                    int nv_y = v_y + dy[k];
                    if (grid[nv_x][nv_y] == 0) {
                        grid[nv_x][nv_y] = memo;
                        que_x.push(nv_x);
                        que_y.push(nv_y);
                    }
                }
            }
            memo++;
        }
    }

    cout << memo-1 << endl;
    return 0;
}