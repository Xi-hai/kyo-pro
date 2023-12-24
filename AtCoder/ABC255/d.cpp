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
    int N, Q; cin >> N >> Q;
    vector<ll> a(N), x(Q);
    rep(i, N) cin >> a[i];
    rep(i, Q) cin >> x[i];
    sort(all(a));
    vector<ll> sum(N+1);//累積和
    rep(i, N) sum[i+1] = sum[i] + a[i];

    rep(i, Q) {
        int left = -1, right = N, mid; //a[left] <= x[i] < a[right]
        do {
            mid = (right + left) / 2;
            if (a[mid] <= x[i]) {
                left = mid;
            } else {
                right = mid;
            }
        } while (right - left > 1);

        if (left == N-1) {
            printf("%lld\n", (ll)N*x[i] - sum[N]);
        } else if (left == -1) {
            printf("%lld\n", sum[N] - (ll)N*x[i]);
        } else {
            printf("%lld\n", (ll)(2*(left+1)-N) * x[i] + sum[N] - 2*sum[left+1]);
        }
    }
    return 0;
}