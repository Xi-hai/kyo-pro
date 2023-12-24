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
const VI dy = {0, 1, 0, -1};
const VI dx = {1, 0, -1, 0};
const VI dy8 = {0, 1, 1, 1, 0, -1, -1, -1};
const VI dx8 = {1, 1, 0, -1, -1, -1, 0, 1};

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

void print_as_bin(int n) {
    string res;
    while (n>0) {
        res += (n%2 ? '1' : '0');
        n /= 2;
    }
    reverse(all(res));
    printf("%s", res.c_str());
}

int main() {
    int n; scanf("%d", &n);
    VVI graph(n);
    vector<set<int>> used_edge(n);
    int u, v;
    rep(i, n-1) {
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    VI star(n); // star[i]: レベルiである星の個数
    VI degree(n); // degree[i]: 頂点iの次数
    rep(i, n) {
        degree[i] = graph[i].size();
    }
    rep(i, n) {
        if (degree[i] < 3) continue;

        // 頂点iはレベル3以上の星の中心
        star[degree[i]]++;
        for (int &nv : graph[i]) {
            used_edge[i].insert(nv);
            used_edge[nv].insert(i);
            degree[nv]--;
        }
    }

    rep(i, n) {
        if (degree[i] != 1) continue;

        int len = 1, current = i;
        do {
            for (int &nv : graph[current]) {
                if (used_edge[current].count(nv)) {
                    continue;
                }

                used_edge[current].insert(nv);
                used_edge[nv].insert(current);
                current = nv;
                len++;
                break;
            }
        } while (degree[current] != 1);

        degree[i] = 0, degree[current] = 0;
        star[2] += len/3;
    }

    rep(i, 2, n) {
        while (star[i] > 0) {
            printf("%d ", i);
            star[i]--;
        }
    }
    printf("\n");
    return 0;
}