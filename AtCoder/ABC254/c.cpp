#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Graph;
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), sorted_a(n);
    Graph v(k), sorted_v(k);
    rep(i, n) {
        cin >> a[i];
        sorted_a[i] = a[i];
        v[i%k].push_back(a[i]);
    }

    sort(all(sorted_a));
    rep(i, n) sorted_v[i%k].push_back(sorted_a[i]);

    rep(i, k) sort(all(v[i]));
    rep(i, k) {
        if (v[i] != sorted_v[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}