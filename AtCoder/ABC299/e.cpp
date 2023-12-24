#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {a = b; return true;}
    return false;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    VVI graph(n);
    rep(m) {
        int u, v; scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int k; scanf("%d", &k);
    VI p(k), d(k);
    rep(i, k) {
        scanf("%d %d", &p[i], &d[i]);
        p[i]--;
    }

    bool black_exist = false;
    VI color(n, -1); // -1:未定, 0:白, 1:黒
    rep(i, k) {
        if (d[i] == 0) {
            color[p[i]] = 1;
            black_exist = true;
            continue;
        }

        // 白でなければならない頂点を白で塗る
        VI dist(n, -1);
        dist[p[i]] = 0;
        queue<int> q;
        q.push(p[i]);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            if (dist[v] == d[i]) continue;
            color[v] = 0;
            for (int nv : graph[v]) {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }
    }

    // 塗られていない頂点をすべて黒で塗る
    rep(i, n) {
        if (color[i] == -1) {
            color[i] = 1;
            black_exist = true;
        }
    }

    // 条件を満たすか確認
    bool ans = true;
    rep(i, k) {
        VI dist(n, -1);
        dist[p[i]] = 0;
        queue<int> q;
        q.push(p[i]);
        bool tmp = false;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (dist[v] == d[i]) {
                if (color[v] == 1) {
                    tmp = true;
                    black_exist = true;
                } else {
                    continue;
                }
            }
            else if (color[v] == 1) {
                ans = false;
                break;
            }

            for (int nv : graph[v]) {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }

        ans = tmp;
        if (!ans) break;
    }

    if (ans & black_exist) {
        printf("Yes\n");
        rep(i, n) printf((color[i]==1) ? "1" : "0");
        printf("\n");
    } else {
        printf("No\n");
    }
    return 0;
}