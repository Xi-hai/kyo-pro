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

bool extendable(int axis, int coor_fix, int& left, int& right) {
    bool res = true;
    if (axis == 0) {
        rep(i, left, right) {
            if (grid[i][coor_fix] != -1) {
                res = false;
                break;
            }
        }
    } else {
        rep(j, left, right) {
            if (grid[coor_fix][j] != -1) {
                res = false;
                break;
            }
        }
    }
    return res;
}

void singleday(mt19937& mt, int t_lim, int d, int threshold) {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    auto now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    uniform_int_distribution<int> dist_k(0, N-1);
    uniform_int_distribution<int> dist_op(0, 7);
    uniform_int_distribution<int> dist_prob(0, 99);
    while (now - start < t_lim) {
        int k = dist_k(mt);
        int operation = dist_op(mt);
        int p_i = rent[d][k][0], p_j = rent[d][k][1], q_i = rent[d][k][2], q_j = rent[d][k][3];
        int area = (q_i - p_i) * (q_j - p_j);
        int prob = dist_prob(mt);

        if (operation%4 == 0) { // 上に伸ばす
            if (p_i == 0) goto NEXT;
            if (!extendable(1, p_i-1, p_j, q_j)) goto NEXT;

            if (area < desired[d][k] || prob < threshold) {
                rent[d][k][0]--, p_i--;
                rep(j, p_j, q_j) grid[p_i][j] = k;
            }
        }
        else if (operation%4 == 1) { // 左に伸ばす
            if (p_j == 0) goto NEXT;
            if (!extendable(0, p_j-1, p_i, q_i)) goto NEXT;

            if (area < desired[d][k] || prob < threshold) {
                rent[d][k][1]--, p_j--;
                rep(i, p_i, q_i) grid[i][p_j] = k;
            }
        }
        else if (operation%4 == 2) { // 下に伸ばす
            if (q_i == W) goto NEXT;
            if (!extendable(1, q_i, p_j, q_j)) goto NEXT;

            if (area < desired[d][k] || prob < threshold) {
                rent[d][k][2]++, q_i++;
                rep(j, p_j, q_j) grid[q_i-1][j] = k;
            }
        }
        else if (operation%4 == 3) { // 右に伸ばす
            if (q_j == W) goto NEXT;
            if (!extendable(0, q_j, p_i, q_i)) goto NEXT;

            if (area < desired[d][k] || prob < threshold) {
                rent[d][k][3]++, q_j++;
                rep(i, p_i, q_i) grid[i][q_j-1] = k;
            }
        }

        if (q_i - p_i > 1 && (operation == 4 || prob < threshold)) { // 下を縮める
            rent[d][k][2]--, q_i--;
            rep(j, p_j, q_j) grid[q_i][j] = -1;
        }
        else if (q_j - p_j > 1 && (operation == 5 || prob < threshold)) { // 右を縮める
            rent[d][k][3]--, q_j--;
            rep(i, p_i, q_i) grid[i][q_j] = -1;
        }
        else if (q_i - p_i > 1 && (operation == 6 || prob < threshold)) { // 上を縮める
            rent[d][k][0]++, p_i++;
            rep(j, p_j, q_j) grid[p_i-1][j] = -1;
        }
        else if (q_j - p_j > 1 && (operation == 7 || prob < threshold)) { // 左を縮める
            rent[d][k][1]++, p_j++;
            rep(i, p_i, q_i) grid[i][p_j-1] = -1;
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
    singleday(mt, 2500, 0, 5);
    VVI mp_itr(N, VI(2));
    rep(k, N) {
        int area = (rent[0][k][2] - rent[0][k][0]) * (rent[0][k][3] - rent[0][k][1]);
        mp_itr[k][0] = area, mp_itr[k][1] = k;
    }
    sort(all(mp_itr));

    // output
    rep(d, D) rep(k, N) rep(t, 4) cout << rent[0][mp_itr[k][1]][t] << (t<3 ? " " : "\n");
    // rep(d, D) rep(k, N) rep(t, 4) cout << rent[0][k][t] << (t<3 ? " " : "\n");
    return 0;
}