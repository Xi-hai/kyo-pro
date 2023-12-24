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

int main() {
    int query; cin >> query;
    multiset<ll> mst;
    rep(query) {
        int type, k; ll x, ans = x;
        cin >> type >> x;
        if (type != 1) cin >> k;

        if (type == 1) {
            mst.insert(x);

        } else if (type == 2) {
            auto itr = mst.upper_bound(x);
            if (itr == mst.begin()) {ans = -1; goto OUT2;}
            else {
                itr--;
            }
            rep(i, k-1) {
                if (itr == mst.begin()) {
                    ans = -1;
                    break;
                }
                itr--;
            }
            
            if (ans != -1) ans = *itr;
            OUT2:
            cout << ans << "\n";

        } else {
            auto itr = mst.lower_bound(x);
            if (itr == mst.end()) {ans = -1; goto OUT3;}
            rep(i, k-1) {
                itr++;
                if (itr == mst.end()) {
                    ans = -1;
                    break;
                }
            }
            
            if (ans != -1) ans = *itr;
            OUT3:
            cout << ans << "\n";
        }
    }
    return 0;
}