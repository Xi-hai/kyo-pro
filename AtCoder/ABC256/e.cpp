#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> Graph;
typedef vector<VI> DPI;
typedef vector<VL> DPL;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
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
    VI x(N);
    VL c(N);
    rep(i, N) {
        cin >> x[i];
        x[i]--;
    }
    rep(i, N) cin >> c[i];
    VL sum_c(N);
    rep(i, N) sum_c[x[i]] += c[i];

    vector<bool> remain(N, true);
    ll ans = 0;
    rep(i, N) {
        int itr;
        ll min_sum = INFI;
        rep(j, N) {
            if (sum_c[j] < min_sum && remain[j]) {
                itr = j;
                min_sum = sum_c[j];
            }
        }

        ans += min_sum;
        remain[itr] = false;
        sum_c[x[itr]] -= c[itr];
    }

    cout << ans << endl;
    return 0;
}