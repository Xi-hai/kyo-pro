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
    int Q, query, x, c;
    set<int> s;
    cin >> Q;

    // 個数管理
    vector<int> cnt(0);
    map<int, int> cast;

    rep(i, Q) {
        cin >> query;
        if (query==1) {
            cin >> x;
            s.insert(x);
            if (cast.count(x)) {
                cnt[cast[x]]++;
            } else {
                cast[x] = cnt.size();
                cnt.push_back(x);
            }
        } else if (query==2) {
            cin >> x >> c;
            if (cast.count(x)) {
                cnt[cast[x]] -= min(c, cnt[cast[x]]);
                if (cnt[cast[x]] == 0) {
                    s.erase(x);
                }
            }
        } else { // query==3
            printf("%d\n", *rbegin(s) - *begin(s));
        }
    }
    return 0;
}