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

const int MAX_N = 69;
int grid[MAX_N][MAX_N];
int N;

bool isin_grid(const int& i, const int& j) {
    if (i<0 || N<=i || j<0 || N<=j) return false;
    return true;
}

ll calc_score(const int& si, const int& sj, const int& cnt_road, string& move) {
    VV<bool> insight(N, V<bool>(N, false));
    insight[si][sj] = true;
    int i = si, j = sj;
    int cost = 0;
    for (char& c : move) {
        if (c=='U') i--;
        else if (c=='D') i++;
        else if (c=='L') j--;
        else j++;
        cost += grid[i][j];

        if (c=='U' || c=='D') {
            int nj = j;
            while (isin_grid(i, nj) && grid[i][nj] > 0) {
                insight[i][nj] = true;
                nj++;
            }
            nj = j;
            while (isin_grid(i, nj) && grid[i][nj] > 0) {
                insight[i][nj] = true;
                nj--;
            }
        } else {
            int ni = i;
            while (isin_grid(ni, j) && grid[ni][j] > 0) {
                insight[ni][j] = true;
                ni++;
            }
            ni = i;
            while (isin_grid(ni, j) && grid[ni][j] > 0) {
                insight[ni][j] = true;
                ni--;
            }
        }
    }
    if (i!=si || j!=sj) return -1;

    int cnt_insight = 0;
    rep(i, N) rep(j, N) if (insight[i][j]) cnt_insight++;
    if (cnt_insight < cnt_road) {
        return (ll)round(10000LL*cnt_insight / (double)cnt_road);
    } else {
        return (ll)round(10000LL + 10000000LL*N / (double)cost);
    }
}

int main() {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    int si, sj; cin >> N >> si >> sj;
    int cnt_road = 0;
    rep(i, N) {
        rep(j, N) {
            char c; cin >> c;
            if (c=='#') grid[i][j] = -1;
            else {
                grid[i][j] = c - '0';
                cnt_road++;
            }
        }
    }

    // string move = "UULLDDDDRRRRRRUULLLL";
    // cout << "score: " << calc_score(si, sj, cnt_road, move) << "\n";
    // auto current = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();;
    // cout << "time: " << current - start << " ms\n";
    return 0;
}