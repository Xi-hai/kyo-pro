#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> Graph;
typedef vector<VI> DPI;
typedef vector<VL> DPL;
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
    int N; cin >> N;
    DPI segment(N, VI(2)); // [L, R)
    rep(i, N) rep(j, 2) cin >> segment[i][j];
    sort(all(segment));
    
    DPI ans(0, VI(2)); // [L, R)
    ans.push_back(segment[0]);

    rep(i, 1, N) {
        int Len = ans.size();
        if (ans[Len-1][1] < segment[i][0]) {
            ans.push_back(segment[i]);
        } else {
            ans[Len-1][1] = max(ans[Len-1][1], segment[i][1]);
        }
    }

    sort(all(ans));
    int Len = ans.size();
    rep(i, Len) {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}