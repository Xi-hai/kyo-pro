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
    ll a, b; scanf("%lld %lld", &a, &b);
    
    // aとbのgcdを求める
    ll GCD = __gcd(a, b);

    // gcdを素因数分解
    set<ll> st;
    st.insert(1LL);
    if (GCD % 2 == 0) {
        st.insert(2LL);
        while (GCD % 2 == 0) GCD /= 2LL;
    }

    for (ll i=3; i*i<=GCD; i+=2LL) {
        if (GCD % i != 0) continue;
        st.insert(i);
        while (GCD % i == 0) GCD /= i;
    }

    st.insert(GCD);

    printf("%d\n", (int)st.size());
    return 0;
}