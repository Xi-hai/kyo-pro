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
    int n, a, count=0;
    cin >> n;
    stack<pair<int, int>>stk;

    rep(i, n) {
        cin >> a;
        count++;
        if (stk.empty()) {
        stk.push(make_pair(a, 1));
        }
        else {
            auto &p =stk.top();
            if (p.first == a) {
                p.second++;
                if (p.second == a) {
                stk.pop();
                count -= a;
                }
            }
            else {
                stk.push(make_pair(a, 1));
            }
        }
        cout << count << endl;
    }
    return 0;
}