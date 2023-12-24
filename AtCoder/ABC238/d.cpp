#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(n) for (int i=0; i<(n); i++)

int main() {
    int t;
    scanf("%d", &t);
    rep(t) {
        ll a, s;
        scanf("%lld %lld", &a, &s);
        s -= 2*a;
        bool ans = (s>=0) && ((s&a) == 0);
        printf(ans ? "Yes\n" : "No\n");
    }
    return 0;
}