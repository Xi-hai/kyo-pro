#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Graph;
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
    int N, M, a, b;
    cin >> N >> M;
    Graph G(N);
    rep(i, M) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int Q, x, k;
    cin >> Q;
    rep(i, Q) {
        cin >> x >> k;
        x--;
        set<int> st;
        vector<queue<int>> next(4);
        next[0].push(x);
        st.insert(x);
        rep(i, k) {
            while (!next[i].empty()) {
                int n = next[i].front();
                next[i].pop();
                rep(j, (int)G[n].size()) {
                    next[i+1].push(G[n][j]);
                    st.insert(G[n][j]);
                }
            }
        }

        int ans=0;
        for (int num : st) {
            ans += num+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}