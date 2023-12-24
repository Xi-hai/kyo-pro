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
const ll MOD = 998244353;
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

void print_as_bin(int n) {
    string res;
    while (n>0) {
        res += (n%2 ? '1' : '0');
        n /= 2;
    }
    reverse(all(res));
    printf("%s", res.c_str());
}

int main() {
    string s; cin >> s;
    int n = s.size();
    VVI dp(n+1, VI(n+1)); // i文字目までで'(' - ')' = jとなる置き換えかた
    dp[0][0] = 1;
    rep(i, n) {
        if (s[i] == '(') {
            rep(j, n) {
                dp[i+1][j+1] = dp[i][j];
            }
        }
        else if (s[i] == ')') {
            rep(j, n) {
                dp[i+1][j] = dp[i][j+1];
            }
        }
        else { // s[i] == '?'のとき
            rep(j, n) {
                dp[i+1][j+1] = dp[i][j];
                dp[i+1][j] += dp[i][j+1];
                dp[i+1][j] %= MOD;
            }
        }
    }

    cout << dp[n][0] << "\n";
    return 0;
}