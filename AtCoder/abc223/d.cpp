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
    int n, m; cin >> n >> m;
    VVI graph(n);
    VI indegree(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        indegree[b]++;
    }

    // トポロジカルソート
    priority_queue<int, VI, greater<int>> pq; // 常に最小を取り出す
    rep(i, n) {
        if (indegree[i] == 0) pq.push(i);
        // sort(all(graph[i]));
    }

    VI sorted;
    while (!pq.empty()) {
        int v = pq.top(); pq.pop();
        sorted.push_back(v);
        for (int nv : graph[v]) {
            indegree[nv]--;
            if (indegree[nv] == 0) pq.push(nv);
        }
    }

    if ((int)sorted.size() == n) {
        rep(i, n) {
            cout << sorted[i]+1 << (i<n-1 ? " " : "\n");
        }
    } else {
        cout << "-1\n";
    }
    return 0;
}