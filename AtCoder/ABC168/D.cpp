#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
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
    int N, M, a, b; cin >> N >> M;
    VVI graph(N, VI(0));
    rep(i, M) {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    VI sign(N, -INFI);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        for (int next : graph[pos]) {
            if (sign[next] >= 0) continue;
            sign[next] = pos;
            q.push(next);
        }
    }

    rep(i, 1, N) {
        if (sign[i]<0) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    rep(i, 1, N) printf("%d\n", sign[i]+1);
    return 0;
}