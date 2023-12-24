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

vector<bool> seen;
bool dfs(const VVI &G, const int &goal, int v) {
    seen[v] = true;
    if (v == goal) return true;
    for (int nv : G[v]) {
        if (seen[nv]) continue;
        if (nv == goal) return true;
        if (dfs(G, goal, nv)) {
            return true;
        }
    }
    return false;
}

bool crossed(int &x1, int &y1, int &r1, int &x2, int &y2, int r2) {
    ll dist_center2 = ((ll)x1 - x2)*(x1 - x2) + ((ll)y1 -y2)*(y1 - y2);
    if (dist_center2 < ((ll)r1 - r2)*(r1 - r2)) return false;
    if (dist_center2 <= ((ll)r1 + r2)*(r1 + r2)) return true;
    return false;
}

int main() {
    int n; scanf("%d", &n);
    int start_x, start_y, goal_x, goal_y;
    scanf("%d %d %d %d", &start_x, &start_y, &goal_x, &goal_y);
    VI x(n), y(n), r(n);
    rep(i, n) scanf("%d %d %d", &x[i], &y[i], &r[i]);

    VVI graph(n);
    rep(i, n) {
        rep(j, i+1, n) {
            if (crossed(x[i], y[i], r[i], x[j], y[j], r[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    int start = -1, goal = -1;
    rep(i, n) {
        if (crossed(x[i], y[i], r[i], start_x, start_y, 0)) {
            start = i;
        }
        if (crossed(x[i], y[i], r[i], goal_x, goal_y, 0)) {
            goal = i;
        }
    }
    
    seen.assign(n, false);
    printf(dfs(graph, goal, start) ? "Yes\n" : "No\n");
    return 0;
}