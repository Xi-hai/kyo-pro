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
    int n;
    string s;
    cin >> n >> s;
    VVI v_RGB(3, VI());
    rep(i, n) {
        if (s[i] == 'R') v_RGB[0].push_back(i);
        else if (s[i] == 'G') v_RGB[1].push_back(i);
        else v_RGB[2].push_back(i);
    }

    VI len_RGB(3);
    rep(i, 3) {
        len_RGB[i] = v_RGB[i].size();
        sort(all(v_RGB[i]));
    }

    ll ans = 0;
    VVI idx = {{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}};
    rep(p, 6) {
        int px = idx[p][0], py = idx[p][1], pz = idx[p][2];
        rep(i, len_RGB[px]) {
            int j_low = upper_bound(all(v_RGB[py]), v_RGB[px][i]) - v_RGB[py].begin();
            rep(j, j_low, len_RGB[py]) {
                int k_low = upper_bound(all(v_RGB[pz]), v_RGB[py][j]) - v_RGB[pz].begin();
                int k_NG = lower_bound(all(v_RGB[pz]), 2*v_RGB[py][j] - v_RGB[px][i]) - v_RGB[pz].begin();
                ans += len_RGB[pz] - k_low;
                if (k_low <= k_NG && k_NG < len_RGB[pz] && v_RGB[pz][k_NG] == 2*v_RGB[py][j] - v_RGB[px][i]) {
                    ans -= 1;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}