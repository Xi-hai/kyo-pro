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
    int N; cin >> N;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    set<pair<int, int>> majic; //覚えた魔法
    rep(i, N) {
        rep(j, i+1, N) {
            int dx = x[j] - x[i], dy = y[j] - y[i];
            int abs_dx = abs(dx), abs_dy = abs(dy);

            int gcd = __gcd(abs_dx, abs_dy);
            dx /= gcd;
            dy /= gcd;
            // printf("(i, j)=(%d, %d): (dx, dy)=(%d, %d)\n", i+1, j+1, dx, dy);

            pair<int, int> p = make_pair(dx, dy);
            if (!majic.count(p)) {
                majic.insert(p);
                p.first *= -1;
                p.second *= -1;
                majic.insert(p);
            }
        }
    }

    cout << majic.size() << endl;
    return 0;
}