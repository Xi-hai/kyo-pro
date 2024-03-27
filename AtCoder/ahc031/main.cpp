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

const int MAX_D = 50;
const int MAX_N = 50;
int W, D, N;
int desired[MAX_D][MAX_N];
VI rent[MAX_D][MAX_N];
VVI grid;

void initialize(mt19937& mt) {
    uniform_int_distribution<int> dist(0, W-1);
    rep(k, N) {
        int p_i = dist(mt);
        int p_j = dist(mt);
        while (grid[p_i][p_j] != -1) {
            p_i = dist(mt);
            p_j = dist(mt);
        }
        rent[0][k] = {p_i, p_j, p_i+1, p_j+1};
        grid[p_i][p_j] = k;
    }
}

void firstday(mt19937& mt, int64_t& start, int t_lim) {
    auto now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    while (now - start < t_lim) {
        uniform_int_distribution<int> dist_k(0, N-1);
        uniform_int_distribution<int> dist_dir(0, 3);
        int k = dist_k(mt);
        int area = (rent[0][k][2] - rent[0][k][0]) * (rent[0][k][3] - rent[0][k][1]);
        int direction = dist_dir(mt);
        int p_i = rent[0][k][0], p_j = rent[0][k][1], q_i = rent[0][k][2]-1, q_j = rent[0][k][3]-1;
        if (area >= desired[0][k]) {
            goto NEXT;
        }
        if (direction == 0) { // 上に伸ばす
            if (p_i == 0) goto NEXT;
            rep(j, p_j, q_j) if (grid[p_i-1][j] != -1) goto NEXT;
            rent[0][k][0]--;
            p_i--;
            rep(j, p_j, q_j) grid[p_i][j] = k;
        }
        else if (direction == 1) { // 左に伸ばす
            if (p_j == 0) goto NEXT;
            rep(i, p_i, q_i) if (grid[i][p_j-1] != -1) goto NEXT;
            rent[0][k][1]--;
            p_j--;
            rep(i, p_i, q_i) grid[i][p_j] = k;
        }
        else if (direction == 2) { // 下に伸ばす
            if (q_i == W-1) goto NEXT;
            rep(j, p_j, q_j) if (grid[q_i+1][j] != -1) goto NEXT;
            rent[0][k][2]++;
            q_i++;
            rep(j, p_j, q_j) grid[q_i][j] = k;
        }
        else if (direction == 3) { // 右に伸ばす
            if (q_j == W-1) goto NEXT;
            rep(i, p_i, q_i) if (grid[i][q_j+1] != -1) goto NEXT;
            rent[0][k][3]++;
            q_j++;
            rep(i, p_i, q_i) grid[i][q_j] = k;
        }

        NEXT:
        now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }
}

int main() {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    random_device rd;
    mt19937 mt(rd());

    // input
    cin >> W >> D >> N;
    rep(d, D) rep(k, N) cin >> desired[d][k];
    grid = VVI(W, VI(W, -1));

    initialize(mt);
    firstday(mt, start, 500);

    // output
    rep(d, D) rep(k, N) rep(t, 4) cout << rent[0][k][t] << (t<3 ? " " : "\n");
    return 0;
}