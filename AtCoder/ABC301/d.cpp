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
    string s, bin_n; ll n;
    cin >> s >> n;
    int len_s = s.size();
    ll m=n;

    for (int i=0; i<len_s | m>0; i++) {
        bin_n += (m%2 ? '1' : '0');
        m /= 2;
    }
    reverse(all(bin_n));
    int len_bin_n = bin_n.size();

    ll min_T = 0, max_T = 0;
    rep(i, len_s) {
        if (s[len_s - 1 - i] == '1') min_T += (1LL<<i);
        if (s[len_s - 1 - i] != '0') max_T += (1LL<<i);
    }

    reverse(all(s));
    rep(i, len_bin_n - len_s) s += '0';
    reverse(all(s));

    // cout << "s:" << s << "\nn=0b" << bin_n << "\nmax:" << max_T << "\nmin:" << min_T << endl;
    
    if (min_T > n) {
        printf("-1\n");
        return 0;
    }
    if (max_T <= n) {
        printf("%lld\n", max_T);
        return 0;
    }
    
    ll ans = min_T;
    rep(i, len_bin_n) {
        if (s[i] == '?' && ans + (1LL << (len_bin_n - 1 - i)) <= n) {
            ans += (1LL << (len_bin_n - 1 - i));
        }
    }

    printf("%lld\n", ans);
    return 0;
}