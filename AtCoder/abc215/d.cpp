#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

const int MAX_M = 101010;

int main() {
    int n, m; cin >> n >> m;
    VI a(n);
    rep(i, n) cin >> a[i];

    VI prime;
    vector<bool> is_prime(MAX_M, true);
    rep(i, 2, MAX_M) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j=2; i*j<MAX_M; j++) {
                if (i*j >= MAX_M) break;
                is_prime[i*j] = false;
            }
        }
    }
    int len_p = prime.size();

    vector<bool> cd(MAX_M, false);
    rep(i, n) {
        rep(j, len_p) {
            if (a[i] < prime[j]) break;
            if (a[i] % prime[j] == 0) {
                cd[prime[j]] = true;
                while (a[i] % prime[j] == 0) {
                    a[i] /= prime[j];
                }
            }
        }
    }

    rep(i, 2, MAX_M) {
        if (cd[i]) {
            for (int j=2; ; j++) {
                if (i*j >= MAX_M) break;
                cd[i*j] = true;
            }
        }
    }

    VI ans;
    rep(i, 1, m+1) {
        if (!cd[i]) {
            ans.push_back(i);
        }
    }
    int cnt = ans.size();

    cout << cnt << "\n";
    rep(i, cnt) cout << ans[i] << "\n";
    return 0;
}