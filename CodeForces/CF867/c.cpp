#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(n) for (int i=0; i<(n); i++)

int main() {
    int t; scanf("%d", &t);
    rep(t) {
        ll n; scanf("%lld", &n);
        printf("%lld\n", n*(n+2) + 2);
    }
    return 0;
}