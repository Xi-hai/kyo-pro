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

/* DFS帰りがけ順
vector<bool> seen;
void dfs(const VVI &G, int v, VI &ans) {
    seen[v] = true;
    //行きがけ
    
    for (int nv : G[v]) {
        if (seen[nv]) continue;
        dfs(G, nv, ans);
    }
    
    //帰りがけ
    ans.push_back(v);
    return;
}

int main() {
    int n; scanf("%d", &n);
    VVI graph(n);
    int c, p;
    rep(i, n) {
        scanf("%d", &c);
        rep(j, c) {
            scanf("%d", &p);
            graph[i].push_back(p-1);
        }
    }

    seen = vector<bool>(n, false);
    VI ans;
    dfs(graph, 0, ans);
    ans.pop_back();
    int len = ans.size();
    rep(i, len) {
        printf(i<len-1 ? "%d " : "%d\n", ans[i]+1);
    }
    return 0;
}
*/

// トポロジカル順序の逆順
int main() {
    int n, p; cin >> n;
    VI c(n), indeg(n);
    VVI graph(n);
    rep(i, n) {
        cin >> c[i];
        rep(j, c[i]) {
            cin >> p;
            p--;
            graph[i].push_back(p);
            indeg[p]++;
        }
    }
    
    vector<bool> use(n, false);
    queue<int> q;
    use[0] = true;
    q.push(0);
    
    while (!q.empty()) {
        int v = q.front(); q.pop();
        
        for (int nv : graph[v]) {
            if (use[nv]) continue;
            use[nv] = true;
            q.push(nv);
        }
    }

    VI sorted;
    rep(i, n) {
        if (indeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        sorted.push_back(v);
        for (int nv : graph[v]) {
            indeg[nv]--;
            if (indeg[nv] == 0) q.push(nv);
        }
    }

    VI order(n);
    rep(i, n) order[sorted[i]] = i;
    VI ans;
    rep(i, n) if (use[i]) ans.push_back(i);
    sort(all(ans), [&](int x, int y) {return order[x] > order[y]; });

    ans.pop_back();
    for (int i : ans) cout << i+1 << " ";
    cout << "\n";
    return 0;
}