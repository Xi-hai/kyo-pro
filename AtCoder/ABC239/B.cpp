#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0; i<n; ++i)
#define repi(i, j, n) for (int i=j; i<=n; ++i)

int main() {
    ll x, detx;
    cin >> x;
    detx = abs(x);
    if (x < 0 && detx % 10 > 0) {
        detx += 10;
    }
    if (x < 0) printf("-");
    printf("%lld\n", detx/10);
    return 0;
}