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

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {a = b; return true;}
    return false;
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {a = b; return true;}
    return false;
}

int main() {
    int n, x, y; scanf("%d %d %d", &n, &x, &y);
    VVI graph(n);
    rep(i, n-1) {
        graph[i].push_back(i+1);
        graph[i+1].push_back(i);
    }
    x--, y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
        
    VI dist, ans(n);
    queue<int> q;
    
    rep(i, n-1) {
        dist.assign(n, -1);
        dist[i] = 0;
        q.push(i);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            
            for (int nv : graph[v]) {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                if (i < nv) ans[dist[nv]]++;
                q.push(nv);
            }
        }
    }

    rep(i, 1, n) printf("%d\n", ans[i]);
    return 0;
}