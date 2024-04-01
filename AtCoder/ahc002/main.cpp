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
typedef pair<int, int> PII;
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
const VI dy = {-1, 1, 0, 0};
const VI dx = {0, 0, -1, 1};
const string UDLR = "UDLR";

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

const int N = 50;
int tiles[N][N];
int points[N][N];
bool visited[N*N];
int64_t start;

VV<bool> seen;
int remaining_cnt = 10000;
void dfs(int i, int j, V<char>& best_move, int& best_score, V<char>& cur_move, int cur_score) {
    // 行きがけ
    seen[i][j] = true;
    visited[ tiles[i][j] ] = true;
    cur_score += points[i][j];
    if (chmax(best_score, cur_score)) {
        best_move = cur_move;
    }
    remaining_cnt--;
    // if (remaining_cnt == 0) return;
    auto current = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    if (current - start > 1950) return;

    rep(k, 4) {
        int ni = i + dy[k], nj = j + dx[k];
        if (ni<0 || N<=ni || nj<0 || N<=nj) continue;
        if (seen[ni][nj] || visited[ tiles[ni][nj] ]) continue;

        cur_move.push_back(UDLR[k]);
        dfs(ni, nj, best_move, best_score, cur_move, cur_score);
        // if (remaining_cnt == 0) return;
        current = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        if (current - start > 1950) return;
    }

    //帰りがけ
    if (!cur_move.empty()) cur_move.pop_back();
    cur_score -= points[i][j];
    seen[i][j] = false;
    visited[ tiles[i][j] ] = false;
    return;
}

int main() {
    start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    int si, sj; cin >> si >> sj;
    rep(i, N) rep(j, N) cin >> tiles[i][j];
    rep(i, N) rep(j, N) cin >> points[i][j];

    fill(visited, visited+N*N, false);
    seen = VV<bool>(N, V<bool>(N, false));
    V<char> best_move(0), cur_move(0);
    int best_score = 0, cur_score = 0;
    dfs(si, sj, best_move, best_score, cur_move, cur_score);
    for (auto& c : best_move) cout << c;
    cout << "\n";
    return 0;
}