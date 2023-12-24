#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Graph;
typedef vector<vector<int>> DPI;
typedef vector<vector<ll>> DPL;
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
    int N, K; cin >> N >> K;
    vector<int> a(K);
    vector<double> x(N), y(N);
    rep(i, K) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, N) cin >> x[i] >> y[i];

    if (K == N) {
        cout << "0\n";
        return 0;
    }

    double ans2=0;
    rep(i, N) {
        //i番目の人に最も近いライト持ちとの距離を調べる
        double dist2 = INFL;
        rep(j, K) {
            double d = (x[i] - x[a[j]]) * (x[i] - x[a[j]]) + (y[i] - y[a[j]]) * (y[i] - y[a[j]]);
            dist2 = min(dist2, d);
        }
        //更新
        ans2 = max(ans2, dist2);
    }
    printf("%.6f\n", sqrt(ans2));
    return 0;
}