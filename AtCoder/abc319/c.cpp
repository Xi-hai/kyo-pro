#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

bool match(VI &grid, int &i, int &j, int &k, VI &order) {
    if (grid[i] == grid[j] && grid[j] != grid[k] &&
        order[i] < order[k] && order[j] < order[k]) return true;
    if (grid[j] == grid[k] && grid[k] != grid[i] &&
        order[j] < order[i] && order[k] < order[i]) return true;
    if (grid[k] == grid[i] && grid[i] != grid[j] &&
        order[k] < order[j] && order[i] < order[j]) return true;
    return false;
}

int main() {
    VI grid(9);
    rep(i, 9) cin >> grid[i];
    int all_pattern = 362880, match_pattern = 0;

    VI order(9);
    rep(i, 9) order[i] = i;
    do {
        bool flg = false;
        // 縦
        rep(i, 3) {
            int j = i+3, k = i+6;
            flg = match(grid, i, j, k, order);
            if (flg) break;
        }
        if (flg) {
            match_pattern++;
            continue;
        }

        // 横
        rep(x, 3) {
            int i = 3*x, j = 3*x+1, k = 3*x+2;
            flg = match(grid, i, j, k, order);
            if (flg) break;
        }
        if (flg) {
            match_pattern++;
            continue;
        }

        // 斜め
        int i = 0, j = 4, k = 8;
        flg = match(grid, i, j, k, order);
        if (flg) {
            match_pattern++;
            continue;
        }
        i = 2, k = 6;
        flg = match(grid, i, j, k, order);
        if (flg) {
            match_pattern++;
            continue;
        }
    } while (next_permutation(all(order)));

    double ans = 1.0 - (1.0 * match_pattern / all_pattern);
    printf("%.10lf\n", ans);
    return 0;
}