#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0; i<n; ++i)
#define repi(i, j, n) for (int i=j; i<n; ++i)

int main () {
	int a, b, c, d, e, f, x, t = 0, Aoki = 0, Taka = 0;
    cin >> a >> b >> c >> d >> e >> f >> x;
    while (t < x) {
        if (t+a <= x) {
            Taka += a*b;
            t += a;
        } else {
            Taka += (x-t) * b;
            t = x;
        }

        if (t < x) {
            t += c;
        }
    }

    t = 0;
    while (t < x) {
        if (t+d <= x) {
            Aoki += d*e;
            t += d;
        } else {
            Aoki += (x-t) * e;
            t = x;
        }

        if (t < x) {
            t += f;
        }
    }

    if (Aoki < Taka) printf("Takahashi\n");
    else if (Aoki > Taka) printf("Aoki\n");
    else printf("Draw\n");
	return 0;
}