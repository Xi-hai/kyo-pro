#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <time.h>
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
    clock_t start = clock(), end;
    int t; scanf("%d", &t);
    rep(t) {
        ll n, p=0, q=0; scanf("%lld", &n);
        if (n%4LL == 0) {p=2LL; q=n/4LL;}
        else if (n%2LL == 0) {q=2LL; p=sqrt(n/q);}
        else {
            for (ll i=3; i<3000000; i+=2) {
                if (n % (i*i) == 0) {
                    p = i;
                    q = n / (p*p);
                } else if (n % i == 0) {
                    q = i;
                    p = sqrt(n / q);
                } else continue;
                break;
            }
        }
        printf("%lld %lld\n", p, q);
    }
    end = clock();
    cout << end - start << endl;
    return 0;
}