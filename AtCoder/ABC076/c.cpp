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
#define rep3(i, a, flag) for (int i=(a); i<(flag); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

int main() {
    string s, t, ans = "UNRESTORABLE";
    cin >> s >> t;
    int s_len = s.size(), t_len = t.size();
    int itr_start = INFI, itr_end = INFI;
    if (s_len < t_len) goto OUT;

    rep(i, (s_len - t_len + 1)) {
        bool flag = true;
        rep(j, t_len) {
            if (s[i+j] == '?') continue;
            if (s[i+j] != t[j]) {
                flag = false;
                break;
            }
        }
        if (flag) itr_start = i;
    }

    if (itr_start > s_len) goto OUT;

    ans = "";
    rep(i, s_len) {
        if (i == itr_start) {
            ans += t;
            i += t_len - 1;
            continue;
        }
        if (s[i] == '?') ans += 'a';
        else ans += s[i];
    }

OUT:
    cout << ans << "\n";
    return 0;
}