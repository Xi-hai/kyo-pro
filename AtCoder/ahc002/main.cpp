#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
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

string greedy(int i, int j, V<bool>& visited) {
    string movement = "";
    while (1) {
        visited[ tiles[i][j] ] = true;

        int p_max = 0, way = -1;
        rep(k, 4) {
            int ni = i + dy[k], nj = j + dx[k];
            if (ni<0 || N<=ni || nj<0 || N<=nj || visited[ tiles[ni][nj] ]) continue;
            if (chmax(p_max, points[ni][nj])) {
                way = k;
            }
        }
        if (way == -1) break;
        movement += UDLR[way];
        i += dy[way];
        j += dx[way];
    }
    return movement;
}

int main() {
    int si, sj; cin >> si >> sj;
    rep(i, N) rep(j, N) cin >> tiles[i][j];
    rep(i, N) rep(j, N) cin >> points[i][j];
    V<bool> visited(N*N, false);
    string output = greedy(si, sj, visited);
    cout << output << "\n";
    return 0;
}