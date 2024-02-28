#define _GLIBCXX_DEBUG
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

int H, W, D, K;
VVI grid(200, VI(200, -1)); // ストレージの状態
VVI data_loc(16000, VI(2)); // ファイルを構成するセクタの位置

// セクタ(r1, c1)と(r2, c2)を入れ替えた場合のコスト変化量の計算
int cost_diff_calc(int r1, int c1, int r2, int c2) {
    int cost_diff = 0;
    int idx1 = grid[r1][c1], idx2 = grid[r2][c2];

    if (idx1 >= 0) {
        if (idx1 > 0 && idx2+1 != idx1) {
            cost_diff -= abs(r1 - data_loc[idx1-1][0]) + abs(c1 - data_loc[idx1-1][1]);
            cost_diff += abs(r2 - data_loc[idx1-1][0]) + abs(c2 - data_loc[idx1-1][1]);
        }
        if (idx1 < D-1 && idx1+1 != idx2) {
            cost_diff -= abs(r1 - data_loc[idx1+1][0]) + abs(c1 - data_loc[idx1+1][1]);
            cost_diff += abs(r2 - data_loc[idx1+1][0]) + abs(c2 - data_loc[idx1+1][1]);
        }
    }
    if (idx2 >= 0) {
        if (idx2 > 0 && idx1+1 != idx2) {
            cost_diff -= abs(r2 - data_loc[idx2-1][0]) + abs(c2 - data_loc[idx2-1][1]);
            cost_diff += abs(r1 - data_loc[idx2-1][0]) + abs(c1 - data_loc[idx2-1][1]);
        }
        if (idx2 < D-1 && idx2+1 != idx1) {
            cost_diff -= abs(r2 - data_loc[idx2+1][0]) + abs(c2 - data_loc[idx2+1][1]);
            cost_diff += abs(r1 - data_loc[idx2+1][0]) + abs(c1 - data_loc[idx2+1][1]);
        }
    }

    return cost_diff;
}

// 実際にセクタ(r1, c1)と(r2, c2)を入れ替える
void sector_swap(int r1, int c1, int r2, int c2) {
    if (grid[r1][c1] >= 0) {
        data_loc[ grid[r1][c1] ][0] = r2;
        data_loc[ grid[r1][c1] ][1] = c2;
    }
    if (grid[r2][c2] >= 0) {
        data_loc[ grid[r2][c2] ][0] = r1;
        data_loc[ grid[r2][c2] ][1] = c1;
    }
    swap(grid[r1][c1], grid[r2][c2]);
}

int main() {
    cin >> H >> W >> D >> K;
    rep(i, D) {
        int row, col;
        cin >> row >> col;
        data_loc[i][0] = row;
        data_loc[i][1] = col;
        grid[row][col] = i;
    }

    // 初期状態のコスト
    int load_cost = 0;
    rep(i, 1, D) {
        rep(j, 2) {
            load_cost += abs(data_loc[i][j] - data_loc[i-1][j]);
        }
    }

    // 前後の移動コストが高いセクタを優先
    VVI swap_priority(D, VI(2, 0));
    rep(i, D) {
        swap_priority[i][1] = i;
        rep(j, 2) {
            if (i>0) {
                swap_priority[i][0] += abs(data_loc[i][j] - data_loc[i-1][j]);
            }
            if (i<D-1) {
                swap_priority[i][0] += abs(data_loc[i][j] - data_loc[i+1][j]);
            }
        }
    }
    sort(all(swap_priority), greater<VI>());

    int cnt_swap = 0;
    rep(i, D) {
        if (cnt_swap>=K) break;
        int v = swap_priority[i][1];
        if (v==0) continue;
        int r_prev = data_loc[v-1][0], c_prev = data_loc[v-1][1];
        rep(j, 8) {
            int nr = r_prev+dy8[j], nc = c_prev+dx8[j];
            if (nr<0 || H<=nr || nc<0 || W<=nc) {
                continue;
            }
            int diff = cost_diff_calc(data_loc[v][0], data_loc[v][1], nr, nc);
            if (diff < -200) {
                printf("%d %d %d %d\n", data_loc[v][0], data_loc[v][1], nr, nc);
                load_cost += diff;
                sector_swap(data_loc[v][0], data_loc[v][1], nr, nc);
                cnt_swap++;
                break;
            }
        }
    }
    return 0;
}