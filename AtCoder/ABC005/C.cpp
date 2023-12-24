#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0; i<n; ++i)

int main () {
	int T, N, M;
    cin >> T >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    cin >> M;
    vector<int> b(M);
    rep(i, M) cin >> b[i];

    int p = 0; // aのイテレータ
    rep(q, M) {
        bool can = false; // q番目の客に提供できるか
        while (p < N) {
            if (a[p] >= b[q] - T && a[p] <= b[q]) {
                can = true;
                ++p;
                break;
            } else {
                ++p;
            }
        }
        if (!can) {
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
	return 0;
}