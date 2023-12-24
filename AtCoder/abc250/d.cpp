#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
const int PRIME_MAX = 1010101;

int main() {
    ll n; cin >> n;
    VL primes;
    V<bool> is_prime(PRIME_MAX, true);
    is_prime[0] = false; is_prime[1] = false;
    rep(i, 2, PRIME_MAX) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (int j=2; i*j<PRIME_MAX; j++) {
            is_prime[i*j] = false;
        }
    }

    int prime_len = primes.size(); // prime_len = 79256
    int p_max = lower_bound(all(primes), 100000) - primes.begin();
    int ans = 0;
    rep(i, p_max) {
        ll p = primes[i];
        if (p > n/27+1) break;
        rep(j, i+1, prime_len) {
            ll q = primes[j];
            ll k = p;
            bool is_under_INFL = true;
            rep(3) {
                if (k > INFL/10000) {
                    is_under_INFL = false;
                    break;
                }
                k *= q;
            }
            if (!is_under_INFL || k>n) break;
            ans++;
        }
    }
    OUT:
    cout << ans << "\n";
    return 0;
}