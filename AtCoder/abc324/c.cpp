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

bool possible_string(int n, int m, string &t, string &s) {
    if (t == s) return true;
    if (n == m) {
        bool changed = false;
        rep(i, n) {
            if (t[i] != s[i]) {
                if (changed) return false;
                else changed = true;
            }
        }
        return true;
    } else if (n+1 == m) {
        int pushed = 0;
        rep(i, n) {
            if (t[i] != s[i + pushed]) {
                if (pushed) return false;
                else if (t[i] == s[i+1]) pushed++;
                else return false;
            }
        }
        return true;
    } else if (n-1 == m) {
        int deleted = 0;
        rep(i, n) {
            if (t[i] != s[i + deleted]) {
                if (deleted < 0) return false;
                else deleted--;
            }
        }
        return true;
    }
    return false;
}

int main() {
    int n; string t; cin >> n >> t;
    VS s(n);
    rep(i, n) cin >> s[i];
    VI ans;

    rep(i, n) {
        if (possible_string(t.size(), s[i].size(), t, s[i])) {
            ans.push_back(i+1);
        }
    }

    int k = ans.size();
    cout << k << "\n";
    rep(i, k) cout << ans[i] << (i<k-1 ? " " : "");
    cout << "\n";
    return 0;
}