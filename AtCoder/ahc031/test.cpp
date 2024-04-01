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
VI grid;

void initialize() {
    int p_i=0;
    rep(k, N) {
        int tmp = desired[0][k]/W;
        if (tmp == 0) tmp++;
        rent[0][k] = {p_i, 0, p_i+tmp, 1000};
        rep(i, p_i, p_i+tmp) grid[i] = k;
        p_i += tmp;
    }
}

void singleday(mt19937& mt, int t_lim, int d) {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    auto now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    uniform_int_distribution<int> dist_k(0, N-1);
    uniform_int_distribution<int> dist_op(0, 1);
    while (now - start < t_lim) {
        int k = dist_k(mt);
        int operation = dist_op(mt);
        int p_i = rent[d][k][0], q_i = rent[d][k][2];
        int area = (q_i - p_i) * 1000;

        if (operation == 0) { // 上に伸ばす
            if (p_i == 0) goto NEXT;

            if (area < desired[d][k]) {
                if (k>0 && rent[d][k-1][2] == p_i) {
                    if (rent[d][k-1][2] - rent[d][k-1][0] == 1) goto NEXT;
                    rent[d][k-1][2]--;
                }
                grid[p_i-1] = k;
                rent[d][k][0]--, p_i--;
            }
        }
        else { // 下に伸ばす
            if (q_i == W) goto NEXT;

            if (area < desired[d][k]) {
                if (k<N-1 && rent[d][k+1][0] == q_i) {
                    if (rent[d][k+1][2] - rent[d][k+1][0] == 1) goto NEXT;
                    rent[d][k+1][0]++;
                }
                grid[q_i] = k;
                rent[d][k][2]++, q_i++;
            }
        }

        NEXT:
        now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }
}

int main() {
    random_device rd;
    mt19937 mt(rd());

    // input
    cin >> W >> D >> N;
    rep(d, D) rep(k, N) cin >> desired[d][k];
    grid = VI(W, -1);

    initialize();
    rep(d, D) {
        if (d>0) {
            rep(k, N) rent[d][k] = rent[d-1][k];
        }
        singleday(mt, 2900/D, d);
    }

    // output
    rep(d, D) rep(k, N) rep(t, 4) cout << rent[d][k][t] << (t<3 ? " " : "\n");
    return 0;
}