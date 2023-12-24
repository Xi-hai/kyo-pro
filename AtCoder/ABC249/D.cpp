#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0; i<n; ++i)
#define repi(i, j, n) for (int i=j; i<n; ++i)

int main () {
	int N, M = 0;
	cin >> N;
	vector<int> a(N), cnt(200001);
	rep(i, N) {
		cin >> a[i];
		++cnt[a[i]];
		M = max(M, a[i]);
	}

	ll ans = 0;
	++M;
	repi(q, 1, M) {
		repi(r, 1, M/q+1) {
			ans += (ll)cnt[q*r] * cnt[q] * cnt[r];
		}
	}
	printf("%lld\n", ans);
	return 0;
}