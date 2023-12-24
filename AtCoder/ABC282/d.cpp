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
    ll n, m; scanf("%lld %lld", &n, &m);
    vector<set<int>> Graph(n);
    int u, v;
    rep(i, m) {
        scanf("%d %d", &u, &v);
        u--; v--;
        Graph[u].insert(v);
        Graph[v].insert(u);
    }

    VI dist(n, -1), cc(n);
    queue<int> q;
    //int t = 0;
    int count = 0;

    // vv[i][j]: cc[v]=i かつ dist[v]%2=j である頂点vの個数
    VVL vv(201010, VL(2, 0));

    rep(u, n) {
        if (dist[u] != -1) continue;
        //dist[u] = t;
        dist[u] = 0;
        q.push(u);
        cc[u] = count;
        count++;

        while (!q.empty()) {
            v = q.front();
            q.pop();
            vv[ cc[v] ][ dist[v]%2 ]++;

            for (int nv : Graph[v]) {
                if (dist[nv] != -1) {
                    // 二部グラフでない場合
                    if (dist[nv] % 2 == dist[v] % 2) {
                        printf("0\n");
                        return 0;
                    } else continue;
                }

                dist[nv] = dist[v] + 1;
                //t = max(t, dist[v] + 2);
                cc[nv] = cc[v];
                //printf("v=%d, nv=%d: t=%d\n", v, nv, t);
                q.push(nv);
            }
        }
    }

    // rep(v, n) printf("v: d=%d, cc=%d\n", dist[v], cc[v]);
    // rep(i, count) {
    //         printf("cc%d: %d, %d\n", i, vv[i][0], vv[i][1]);
    // }

    // int sum = n;

    ll ans = n * (n-1) / 2 - m;
    rep(i, count) {
        ans -= vv[i][0] * (vv[i][0] - 1) / 2;
        ans -= vv[i][1] * (vv[i][1] - 1) / 2;
    }
    // rep(v, n) {
    //     ans += n - vv[ cc[v] ][ dist[v] % 2 ] - Graph[v].size();
    //     // printf("v=%d: %d\n", v, n - vv[ cc[v] ][ dist[v] % 2 ] - (int)Graph[v].size());
    //     // ans += sum - vv[cc[v]][0] - vv[cc[v]][1];
    // }
    printf("%lld\n", ans);
    return 0;
}