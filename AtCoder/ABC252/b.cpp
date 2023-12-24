#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
typedef vector<vector<int>> Graph;

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int b;
    set<int> dislike;
    rep(i, k) {
        cin >> b;
        dislike.insert(b-1);
    }

    int m=0;
    vector<int> a_itr(0);
    rep(i, n) {
        if (m < a[i]) {
            m = a[i];
            a_itr = vector<int>(1);
            a_itr[0] = i;
        } else if (m == a[i]) {
            a_itr.push_back(i);
        }
    }

    rep(i, a_itr.size()) {
        if (dislike.count(a_itr[i])) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}