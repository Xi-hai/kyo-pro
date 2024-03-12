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

struct coord {
    int x, y;
};

const int N = 100;
int grid[N][N];
int height[N][N];

bool isin_grid(const int& i, const int& j) {
    if (i<0 || N<=i || j<0 || N<=j) return false;
    return true;
}

void mountain_sum(const int& x, const int& y, const int& h, const int& r) {
    rep(j, max(0, y-r+1), min(N, y+r)) {
        rep(i, max(0, x-r+1), min(N, x+r)) {
            if (h>0) height[j][i] += max(0, h - abs(j-y) - abs(i-x));
            else height[j][i] += max(h, abs(j-y) + abs(i-x) - r);
        }
    }
}

int main() {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    rep(j, N) rep(i, N) cin >> grid[j][i];

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, N-1);
    int Q = 1000;
    // coord out_c[Q];
    // int out_h[Q];
    VI added[N][N];
    rep(t, Q) {
        int x = dist(mt), y = dist(mt), h = dist(mt)+ 1;
        mountain_sum(x, y, h, h);
        // out_c[t] = {x, y};
        // out_h[t] = h;
        added[y][x].push_back(h);
        // printf("%d %d %d\n", x, y, h);
    }

    ll diff = 0;
    // priority_queue<VI> pq; // {diff(>0), 座標}
    rep(j, N) {
        rep(i, N) {
            int tmp = abs(height[j][i] - grid[j][i]);
            diff += tmp;

            // pq.push({tmp, i, j});
            // sort(all(added[j][i]), greater<int>());
        }
    }
    auto current = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    printf("time: %ld ms\n", current - start);
    printf("diff: %Ld\n", diff);

    // VVI itr(N, VI(N));
    // while (current - start < 1900 && !pq.empty()) {
    //     int d, x, y;
    //     {
    //         auto tmp = pq.top();
    //         pq.pop();
    //         d = tmp[0];
    //         x = tmp[1], y = tmp[2];
    //     }

    //     if (abs(height[y][x] - grid[y][x]) < 10 || added[y][x].empty()) continue;
    //     int i = itr[y][x];
    //     if (i >= (int)added[y][x].size()) continue;
    //     chmin(d, added[y][x][i]);
    //     mountain_sum(x, y, -d, added[y][x][i]);
    //     added[y][x][i] -= d;
    //     itr[y][x]++;

    //     current = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    // }

    // printf("%d\n", Q);
    // // rep(i, Q) {
    // //     printf("%d %d %d\n", out_c[i].x, out_c[i].y, out_h[i]);
    // // }
    // rep(j, N) {
    //     rep(i, N) {
    //         for (auto& out : added[j][i]) {
    //             printf("%d %d %d\n", i, j, out);
    //         }
    //     }
    // }
    return 0;
}