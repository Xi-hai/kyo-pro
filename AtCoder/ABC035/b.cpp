#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
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
    string s; cin >> s;
    int N = s.size(), t, x=0, y=0, unknown=0;
    rep(i, N) {
        if (s[i] == 'R') x++;
        if (s[i] == 'L') x--;
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        if (s[i] == '?') unknown++;
    }

    int dist = abs(x) + abs(y);
    cin >> t;
    if (t==1) dist += unknown;
    else {
        if (dist >= unknown) dist -= unknown;
        else if (dist % 2 == unknown % 2) dist = 0;
        else dist = 1;
    }
    cout << dist << endl;
    return 0;
}