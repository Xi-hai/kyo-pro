#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> VL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

int main() {
    ll n; scanf("%lld", &n);
    vector<bool> is_prime(301010, true);
    VL prime_num;
    rep(i, 2, 301010) {
        if (is_prime[i]) {
            prime_num.emplace_back(i);
            for (int j=2*i; j < 301010; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int ans = 0, psiz = prime_num.size();
    rep(i, 300) {
        if (prime_num[i] > 500) break;
        rep(j, i+1, 10101) {
            if (prime_num[j] > 20000) break;

            ll a2b = prime_num[i] * prime_num[i] * prime_num[j];
            if (a2b * prime_num[j] * prime_num[j] > n) break;

            for (int k = psiz - 1; k>j; k--) {
                if (a2b * prime_num[k] * prime_num[k] <= n) {
                    ans += k-j;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}