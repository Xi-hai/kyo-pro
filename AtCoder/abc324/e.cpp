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
    int n; string t; cin >> n >> t;
    VS s(n); rep(i, n) cin >> s[i];
    int t_len = t.size();
    // substr_len[i][j]: s[i]はtの先頭/末尾(j==0/1)から何文字を部分列として含むか(最大値)
    VVI substr_len(n, VI(2));
    rep(i, n) {
        int s_len = s[i].size();
        int j=0;
        rep(k, s_len) {
            if (t[j] == s[i][k]) {
                substr_len[i][0]++;
                j++;
                if (j==t_len) break;
            }
        }
        j=t_len-1;
        rep(k, s_len) {
            if (t[j] == s[i][s_len-1 - k]) {
                substr_len[i][1]++;
                j--;
                if (j<0) break;
            }
        }
    }

    VVI cnt(2, VI(t_len+1));
    rep(i, n) {
        cnt[0][ substr_len[i][0] ]++;
        cnt[1][ substr_len[i][1] ]++;
    }
    VVI subsum_cnt(2, VI(t_len+1));
    rep(j, 2) {
        rep(i, t_len) {
            subsum_cnt[j][i+1] = subsum_cnt[j][i] + cnt[j][i];
        }
    }

    ll ans = 0;
    rep(i, n) {
        // s[i]を先頭として連結して条件を満たす個数
        int len_tail = t_len - substr_len[i][0];
        ans += n - subsum_cnt[1][len_tail];
    }
    cout << ans << "\n";
    return 0;
}