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

int main() {
    int n; cin >> n;
    VL v(n+1, 0), sum(n+1, 0);
    priority_queue<ll, VL, greater<ll>> pq;
    rep(i, n) {
        sum[i+1] = sum[i];
        int p;
        cin >> p;
        if (p == 1) {
            ll x; cin >> x;
            pq.push(x - sum[i+1]);
        } else if (p == 2) {
            cin >> v[i+1];
            sum[i+1] += v[i+1];
        } else {
            ll num = pq.top(); pq.pop();
            cout << (num + sum[i+1]) << "\n";
        }
    }
    return 0;
}