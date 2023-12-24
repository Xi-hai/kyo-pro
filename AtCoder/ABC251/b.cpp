#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
typedef vector<vector<int>> Graph;

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

int main() {
    int n, w; cin >> n >> w;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<bool> b(w+1, false);

    rep(i, n) {
        if (a[i]<=w) b[a[i]]=1;
        rep(j, i+1, n) {
            if (a[j]<=w) b[a[j]]=1;
            if (a[i]+a[j]<=w) b[a[i]+a[j]]=1;
            rep(k, j+1, n) {
                if (a[k]<=w) b[a[k]]=1;
                if (a[i]+a[k]<=w) b[a[i]+a[k]]=1;
                if (a[j]+a[k]<=w) b[a[j]+a[k]]=1;
                if (a[i]+a[j]+a[k]<=w) b[a[i]+a[j]+a[k]]=1;
            }
        }
    }

    int ans=0;
    rep(i, w+1) {
        if (b[i]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}