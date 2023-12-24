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

typedef pair<ll, int> P; //first: 最短距離, second: 頂点番号

int n;
ll a, b, c;
const int MAX_N = 1000;
ll G[MAX_N][MAX_N];
ll d[MAX_N];

void dijkstra(int s, int fb) {
    // firstが小さい順に取り出される
    priority_queue<P, vector<P>, greater<P>> pq;
    fill(d, d+n, INFL);
    d[s] = 0;
    pq.push(P(0, s));

    while (!pq.empty()) {
        P p = pq.top(); pq.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        rep(to, n) {
            if (fb == 0 && chmin(d[to], d[v] + G[v][to]*a)) {
                pq.push(P(d[to], to));
            }
            if (fb == 1 && chmin(d[to], d[v] + G[v][to]*b + c)) {
                pq.push(P(d[to], to));
            }
        }
    }
}

int main() {
    cin >> n >> a >> b >> c;
    rep(i, n) rep(j, n) cin >> G[i][j];

    dijkstra(0, 0);
    VL dist_forward(n);
    rep(i, n) dist_forward[i] = d[i];

    dijkstra(n-1, 1);
    VL dist_backward(n);
    rep(i, n) dist_backward[i] = d[i];

    ll ans = INFL;
    rep(i, n) chmin(ans, dist_forward[i] + dist_backward[i]);
    cout << ans << "\n";
    return 0;
}