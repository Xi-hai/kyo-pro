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

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {a = b; return true;}
    return false;
}

int main() {
    int n; cin >> n;
    VVI v(n);
    int f, s;
    rep(i, n) {
        cin >> f >> s;
        f--;
        v[f].push_back(s);
    }
    rep(i, n) sort(all(v[i]), greater<int>());
    VI tmax;
    rep(i, n) {
        if ((int)v[i].size() > 0) tmax.push_back(v[i][0]);
    }
    sort(all(tmax), greater<int>());
    int ans = 0;
    if ((int)tmax.size() > 1) {
        ans = tmax[0] + tmax[1];
    }

    rep(i, n) {
        if ((int)v[i].size() < 2) continue;
        chmax(ans, v[i][0] + v[i][1]/2);
    }
    cout << ans << "\n";
    return 0;
}