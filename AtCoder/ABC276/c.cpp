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

int main() {
    int n; cin >> n;
    VI p(n);
    rep(i, n) cin >> p[i];

    int start_itr=0;
    VI sub_p(1);
    rep(i, n-1) {
        if (p[i] > p[i+1]) {
            start_itr = i;
            sub_p = {p[i+1]};
        } else {
            sub_p.push_back(p[i+1]);
        }
    }

    int new_start = sub_p[0], new_itr = 0, len = sub_p.size();
    rep(i, len) {
        if (sub_p[i] < p[start_itr]) {
            new_start = sub_p[i];
            new_itr = i;
        }
    }

    sub_p[new_itr] = p[start_itr];
    sort(all(sub_p), greater<int>());

    rep(i, start_itr) printf("%d ", p[i]);
    printf("%d ", new_start);
    rep(j, len) printf("%d ", sub_p[j]);
    // printf("\n");
    return 0;
}