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
    int t; scanf("%d", &t);
    rep(t) {
        int n; scanf("%d", &n);
        string s; cin >> s;
        int charac = 0;
        if (s[0] != 'm' && s[0] != 'M') goto END;
        rep(i, n) {
            if (charac == 0) {
                if (s[i] == 'e' || s[i] == 'E') charac++;
                else if (s[i] != 'm' && s[i] != 'M') {
                    charac = -1;
                    break;
                }
            } else if (charac == 1) {
                if (s[i] == 'o' || s[i] == 'O') charac++;
                else if (s[i] != 'e' && s[i] != 'E') {
                    charac = -1;
                    break;
                }
            } else if (charac == 2) {
                if (s[i] == 'w' || s[i] == 'W') charac++;
                else if (s[i] != 'o' && s[i] != 'O') {
                    charac = -1;
                    break;
                }
            } else { // charac == 3
                if (s[i] != 'w' && s[i] != 'W') {
                    charac = -1;
                    break;
                }
            }
        }

        END:
        printf(charac == 3 ? "YES\n" : "NO\n");
    }
    return 0;
}