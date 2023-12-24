#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
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

typedef pair<ll, ll> PLL;

// keyより大きい最小値のidxを返す
int binary_search(const V<PLL> &v, ll key) {
    int left = -1, right = (int)v.size();
    
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (v[mid].first > key) right = mid;
        else left = mid;
    }
    // v[left].first <= key < v[right].first
    return right;
}

int main() {
    int n; cin >> n;
    VL t(n), d(n);
    rep(i, n) cin >> t[i] >> d[i];
    V<PLL> in_sort(n);
    rep(i, n) {
        in_sort[i] = PLL(t[i], i);
    }
    sort(all(in_sort));

    priority_queue<PLL> pq;
    ll t_current = 0;
    rep(i, n) {
        int idx = in_sort[i].second;
        pq.push(PLL(t[idx] + d[idx], idx));
        t_current = t[idx];
    }
    return 0;
}