#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0; i<n; ++i)
#define repi(i, j, n) for (int i=j; i<n; ++i)

int main () {
	vector<int> r(2), c(2);
    rep(i, 2) cin >> r[i] >> c[i];
    int ans;

    if (r[0] == r[1] && c[0] == c[1]) {
        ans = 0;
    }

    else if (r[0] + c[0] == r[1] + c[1] || r[0] - c[0] == r[1] - c[1] || abs(r[0] - r[1]) + abs(c[0] - c[1]) <= 3) {
        ans = 1;
    }

    else if (abs(r[0] + c[0] - r[1] - c[1]) <= 3 || abs(r[0] - c[0] - r[1] + c[1]) <= 3 ||
             (r[0] + c[0]) % 2 == (r[1] - c[1]) % 2 || (r[0] - c[0]) % 2 == (r[1] + c[1]) % 2 ||
             abs(r[0] - r[1]) + abs(c[0] - c[1]) <= 6) {
        ans = 2;
    }
    else {ans = 3;}
    printf("%d\n", ans);
	return 0;
}