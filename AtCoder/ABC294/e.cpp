#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<ll, ll> PLL;
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
    ll L; int n1, n2; scanf("%lld %d %d", &L, &n1, &n2);
    ll ans = 0, x = 0, len;
    VI v1(n1), v2(n2);
    vector<PLL> lr1(n1), lr2(n2);
    rep(i, n1) {
        scanf("%d %lld", &v1[i], &len);
        lr1[i] = {x, x+len};
        x += len;
    }
    x = 0;
    rep(i, n2) {
        scanf("%d %lld", &v2[i], &len);
        lr2[i] = {x, x+len};
        x += len;
    }

    int j = 0;
    rep(i, n1) {
        while (lr2[j].first < lr1[i].second) {
            if (v1[i] != v2[j]) {
                if (lr1[i].second < lr2[j].second) break;
                if (j<n2-1) j++;
                else break;
                continue;
            }
            ans += min(lr1[i].second, lr2[j].second) - max(lr1[i].first, lr2[j].first);
            if (lr1[i].second < lr2[j].second) break;
            if (j<n2-1) j++;
            else break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}