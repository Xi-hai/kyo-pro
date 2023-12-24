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

int main() {
    int n; cin >> n;
    map<ll, ll> slimes; // slimes[i]: サイズiのスライムの数
    rep(i, n) {
        ll siz, cnt; cin >> siz >> cnt;
        slimes[siz] += cnt;
        cnt = slimes[siz];
        while (cnt > 0) {
            slimes[2*siz] += cnt/2;
            slimes[siz] %= 2;
            if (slimes[siz] == 0) slimes.erase(siz);
            cnt = slimes[2*siz];
            siz *= 2;
        }
    }

    ll ans = 0;
    for (const auto& s : slimes) {
        // cout << s.first << ": " << s.second << "\n";
        ans += s.second;
    }
    cout << ans << "\n";
    return 0;
}