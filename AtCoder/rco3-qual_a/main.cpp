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

struct coordinate {
    int x;
    int y;
};

struct mean_variance {
    double ave;
    double var;
};

double dist_sq(V<coordinate>& c_pos, int& i, int& j) {
    return (c_pos[i].x - c_pos[j].x)*(c_pos[i].x - c_pos[j].x) + (c_pos[i].y - c_pos[j].y)*(c_pos[i].y - c_pos[j].y);
}

// 訪問順が決まっているときの分散と平均を計算
mean_variance calc_initial_stats(int& n, V<coordinate>& c_pos, VI& it_map) {
    mean_variance res = {0, 0};
    V<double> dist(n);
    rep(i, n) {
        dist[i] = sqrt( dist_sq(c_pos, it_map[(i+1)%n], it_map[i]) );
        res.ave += dist[i];
    }

    res.ave /= n;
    rep(i, n) {
        res.var += (dist[i] - res.ave)*(dist[i] - res.ave);
    }
    res.var /= n;
    return res;
}

// p日目とq日目の都市を入れ替えた場合の分散と平均値の変化量を計算する
mean_variance calc_stats_diff(int& n, V<coordinate>& c_pos, VI& it_map, double ave, int p, int q) {
    mean_variance diff = {0, 0};
    double tmp;
    int p_prev = p-1, p_next = p+1, q_prev = q-1, q_next = q+1;
    if (p_prev==-1) p_prev = n-1;
    if (p_next==n) p_next = 0;
    if (q_prev==-1) q_prev = n-1;
    if (q_next==n) q_next = 0;

    /*
    - (p_prev -> p)
    - (p -> p_next)
    - (q_prev -> q)
    - (q -> q_next)
    + (p_prev -> q)
    + (q -> p_next)
    + (q_prev -> p)
    + (p -> q_next)
    */
    if (q_next != p) {
        tmp = dist_sq(c_pos, it_map[p_prev], it_map[p]);
        diff.var -= tmp;
        diff.ave -= sqrt(tmp);

        tmp = dist_sq(c_pos, it_map[p_prev], it_map[q]);
        diff.var += tmp;
        diff.ave += sqrt(tmp);

        tmp = dist_sq(c_pos, it_map[q], it_map[q_next]);
        diff.var -= tmp;
        diff.ave -= sqrt(tmp);

        tmp = dist_sq(c_pos, it_map[p], it_map[q_next]);
        diff.var += tmp;
        diff.ave += sqrt(tmp);
    }

    if (p_next != q) {
        tmp = dist_sq(c_pos, it_map[p], it_map[p_next]);
        diff.var -= tmp;
        diff.ave -= sqrt(tmp);

        tmp = dist_sq(c_pos, it_map[q], it_map[p_next]);
        diff.var += tmp;
        diff.ave += sqrt(tmp);

        tmp = dist_sq(c_pos, it_map[q_prev], it_map[q]);
        diff.var -= tmp;
        diff.ave -= sqrt(tmp);

        tmp = dist_sq(c_pos, it_map[q_prev], it_map[p]);
        diff.var += tmp;
        diff.ave += sqrt(tmp);
    }

    diff.var /= n;
    diff.ave /= n;
    diff.var -= diff.ave*(2*ave + diff.ave);
    return diff;
}

int main() {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    int n; cin >> n;
    V<coordinate> c_pos(n);
    rep(i, n) cin >> c_pos[i].x >> c_pos[i].y;
    VI it_map(n);
    rep(i, n) it_map[i] = i;
    mean_variance stats = calc_initial_stats(n, c_pos, it_map);
    // printf("initial variance: %10lf\ninitial average: %10lf\n", stats.var, stats.ave);

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> uni_dist(0, n-1);

    // 変化量計算のテスト
    // mean_variance difference = calc_stats_diff(n, c_pos, it_map, stats.ave, 1, 2);
    // stats.var += difference.var;
    // stats.ave += difference.ave;
    // printf("final variance: %10lf\nfinal average: %10lf\n", stats.var, stats.ave);

    // ランダム探索
    auto current = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    while (current - start < 1950) {
        int p = uni_dist(mt);
        int q = uni_dist(mt);
        if (p==q) continue;
        mean_variance diff = calc_stats_diff(n, c_pos, it_map, stats.ave, p, q);
        if (diff.var < 0.0) {
            swap(it_map[p], it_map[q]);
            stats.ave += diff.ave;
            stats.var += diff.var;
        }

        current = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }

    // printf("final variance: %10lf\nfinal average: %10lf\n", stats.var, stats.ave);
    rep(i, n) printf("%d\n", it_map[i]);
    return 0;
}