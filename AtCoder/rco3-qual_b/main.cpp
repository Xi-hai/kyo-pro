#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using chrono::duration_cast;
using chrono::milliseconds;
using chrono::system_clock;
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

VV<bool> seen;
int dfs(const int& N, const VVI& quality, VV<bool>& union_graph, int i, int j) {
    int res = 0;
    seen[i][j] = true;
    //行きがけ
    union_graph[i][j] = true;
    res++;
    rep(k, 4) {
        int ni = i+dy[k], nj = j+dx[k];
        if (ni<0 || N<=ni || nj<0 || N<=nj) continue;
        if (seen[ni][nj]) continue;
        if (quality[i][j] == quality[ni][nj]) {
            res += dfs(N, quality, union_graph, ni, nj);
        }
    }

    //帰りがけ
    return res;
}

void caring(VVI& quality, int i, int j) {
    if (quality[i][j] != 0) {
        quality[i][j]++;
    }
}

int harvesting(int N, VVI& quality, int i, int j) {
    if (quality[i][j] == 0) return 0;
    int res = 0, k = quality[i][j];
    VV<bool> union_graph(N, V<bool>(N, false));
    seen = VV<bool>(N, V<bool>(N, false));
    int union_size = dfs(N, quality, union_graph, i, j);
    if (union_size >= k) {
        res = k*union_size;
        rep(h, N) {
            rep(w, N) {
                if (union_graph[h][w]) quality[h][w] = 0;
            }
        }
    }
    return res;
}

int main() {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    int N, M; cin >> N >> M;
    VVI quality(N, VI(N));
    rep(i, N) rep(j, N) cin >> quality[i][j];

    int sum = 0;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist_op(1, 2);
    uniform_int_distribution<int> dist_co(0, N-1);

    // 出力から得点計算
    // int q; cin >> q;
    // rep(q) {
    //     int op, i, j;
    //     cin >> op >> i >> j;
    //     if (op == 1) caring(quality, i, j);
    //     else sum += harvesting(N, quality, i, j);
    // }
    // cout << "sum: " << sum << "\n";
    // rep(i, N) {
    //     rep(j, N) cout << quality[i][j] << " ";
    //     cout << "\n";
    // }

    rep(M) {
        auto current = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        if (current - start > 1950) break;

        int op = dist_op(mt);
        int i = dist_co(mt);
        int j = dist_co(mt);
        if (op == 1) caring(quality, i, j);
        else {
            sum += harvesting(N, quality, i, j);
        }
        printf("%d %d %d\n", op, i, j);
    }

    // printf("score: %d\n", sum);
    return 0;
}