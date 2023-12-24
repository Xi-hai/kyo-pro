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
    string str; cin >> str;
    int n = str.size();
    VVI sum(n+1, VI(10, 0));
    rep(i, n) {
        rep(j, 10) sum[i+1][j] = sum[i][j];
        int r = str[i] - '0';
        sum[i+1][r]++;
    }

    VVI mem(2<<10);
    rep(i, n+1) {
        int bit = 0;
        rep(j, 10) {
            bit += (sum[i][j]%2) << j;
        }
        mem[bit].push_back(i);
    }

    ll ans = 0;
    rep(i, (2<<10)) {
        ll siz = mem[i].size();
        ans += siz * (siz-1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}