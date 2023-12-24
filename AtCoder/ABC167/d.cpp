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
    int n; ll k; cin >> n >> k;
    VI to(n);
    rep(i, n) {
        cin >> to[i];
        to[i]--;
    }

    int nv = 0, cycle_start = -1, cycle_len = -1;
    VI dist(n, -1);
    dist[0] = 0;
    rep(n) {
        int v = nv;
        nv = to[v];
        if (dist[nv] == -1) {
            dist[nv] = dist[v] + 1;
        } else {
            cycle_start = nv;
            cycle_len = dist[v] - dist[nv] + 1;
            break;
        }
    }

    if (k >= dist[cycle_start]) {
        k -= dist[cycle_start];
        k %= cycle_len;
        k += dist[cycle_start];
    }
    rep(i, n) {
        if (dist[i] == k) {
            cout << i+1 << "\n";
            break;
        }
    }
    return 0;
}