#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

int main() {
    ll N, Q, b, c, sum=0;
    cin >> N;
    vector<ll> a(N), cnt(100001);
    rep(i, N) {
        cin >> a[i];
        sum += a[i];
        ++cnt[a[i]];
    }

    cin >> Q;
    rep(i, Q) {
        cin >> b >> c;
        sum += (c-b) * cnt[b];
        cnt[c] += cnt[b];
        cnt[b] = 0;
        printf("%lld\n", sum);
    }
    return 0;
}