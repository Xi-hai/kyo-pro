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

int main() {
    int t; cin >> t;
    rep(t) {
        int n, start=-1, end=-1;
        char c;
        string s;
        cin >> n >> c >> s;
        rep(i, n) {
            if (s[i] == c && start<0) start = i;
            if (s[i] == 'g' && end<0) end = i;
        }

        int ans = 0, time = 0;
        bool b = false;
        rep(i, start, n+end+1) {
            if (s[i%n] == c && !b) {
                time = 0;
                b = true;
            }
            if (s[i%n] == 'g' && b) {
                ans = max(ans, time);
                b = false;
            }
            time++;
        }

        printf("%d\n", ans);
    }
    return 0;
}