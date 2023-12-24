#define _GLIBCXX_DEBUG
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

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

int main() {
    int n, m, u, v; scanf("%d %d", &n, &m);
    VVI Graph(n);
    rep(i, m) {
        scanf("%d %d", &u, &v);
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    VI dist(n, -1);
    queue<int> q;
    int count = 0;
    rep(i, n) {
        if (dist[i] != -1) continue;
        dist[i] = 0; q.push(i);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int nv : Graph[v]) {
                if (dist[nv] == -1) {
                    dist[nv] = dist[v] + 1;
                    q.push(nv);
                }
            }
        }
        count++;
    }
    printf("%d\n", count);
    return 0;
}