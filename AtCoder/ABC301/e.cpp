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


template <typename T>
void print_as_bin(T n) {
    string res;
    while (n>0) {
        res += (n%2 ? '1' : '0');
        n /= 2;
    }
    reverse(all(res));
    printf("%s", res.c_str());
}

template <typename T>
int bit_count(T bit) {
    int res = 0;
    while (bit>0) {
        res += bit%2;
        bit /= 2;
    }
    return res;
}

int h, w, t, sweets_cnt;

bool in_grid(const VI &v) {
    if (v[0] < 0 || h <= v[0] || v[1] < 0 || w <= v[1]) return false;
    else return true;
}

VI bfs(const VVI &grid, const int &start_num, const VVI &sweets_pos) {
    queue<VI> q;
    VVI dist(h, VI(w, INFI/2)); // 指定した頂点から壁マスを除く全マスまでの最短距離.
    dist[sweets_pos[start_num][0]][sweets_pos[start_num][1]] = 0;
    q.push({sweets_pos[start_num]});

    while (!q.empty()) {
        VI pos_v = q.front(); q.pop();
        
        rep(i, 4) {
            VI pos_nv = {pos_v[0] + dy[i], pos_v[1] + dx[i]};
            if (! in_grid(pos_nv)) continue;
            if (grid[pos_nv[0]][pos_nv[1]] == -1) continue;
            if (dist[pos_nv[0]][pos_nv[1]] < INFI/2) continue;

            dist[pos_nv[0]][pos_nv[1]] = dist[pos_v[0]][pos_v[1]] + 1;
            q.push(pos_nv);
        }
    }

    VI res(20, -1); // 指定した頂点から全頂点までの最短距離.
    rep(i, sweets_cnt+1) {
        res[i] = dist[sweets_pos[i][0]][sweets_pos[i][1]];
    }
    return res;
}

int main() {
    scanf("%d %d %d", &h, &w, &t);
    VVI sweets_pos(20), grid(h, VI(w));
    VS a(h);
    sweets_cnt=1; //0:Start, size+1:Goal
    rep(i, h) {
        cin >> a[i];
        rep(j, w) {
            if (a[i][j] == 'o') {
                grid[i][j] = sweets_cnt;
                sweets_pos[sweets_cnt] = {i, j};
                sweets_cnt++;
            }
            else if (a[i][j] == '#') grid[i][j] = -1;
            else if (a[i][j] == 'S') {
                grid[i][j] = 100;
                sweets_pos[0] = {i, j};
            }
            else if (a[i][j] == 'G') {
                grid[i][j] = 101;
                sweets_pos[19] = {i, j};
            }
        }
    }
    // この時点で sweets_cnt = (お菓子マスの数)+1 になっている.
    sweets_pos[sweets_cnt] = sweets_pos[19];

    // BFS
    // S, G, お菓子マスを頂点として、全頂点間最短距離を求める.
    VVI dist(20);
    rep(i, sweets_cnt) {
        dist[i] = bfs(grid, i, sweets_pos);
    }

    // bit DP
    // dp[S][i]: Sに含まれる全頂点(お菓子マス)を訪問し最後に頂点iにいるときの最短経路長.
    // bit%2 == 0に関してはnull(Startを訪問しないのはありえない).
    VVL dp((1 << (sweets_cnt+1)), VL(sweets_cnt+1, INFL));
    dp[1][0] = 0LL;
    int ans = -1;

    rep(bit, (1 << sweets_cnt)) { // Goalに到達したならそれ以上移動しない.
        if (!(bit & 1)) continue;
        rep(i, sweets_cnt) {
            // 頂点iに到達した時点ですでにT回だけ移動したなら、それ以上は移動できない.
            if (((bit >> i) & 1) && dp[bit][i] < t) {
                rep(j, 1, sweets_cnt+1) {
                    // i->jに向かう
                    chmin( dp[bit | (1 << j)][j], dp[bit][i] + dist[i][j] );
                }

                // Goalに到達できるならansを更新.
                if (dp[bit | (1 << sweets_cnt)][sweets_cnt] <= t) {
                    chmax(ans, bit_count(bit/2)); // startの分は除外.
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}