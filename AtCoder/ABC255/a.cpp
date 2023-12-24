#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Graph;
typedef vector<vector<int>> DPI;
typedef vector<vector<ll>> DPL;
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
    int r, c;
    cin >> r >> c;
    Graph a(2, vector<int>(2));
    rep(i, 2) rep(j, 2) cin >> a[i][j];
    cout << a[r-1][c-1] << endl;
    return 0;
}