#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0; i<n; ++i)
#define repi(i, j, n) for (int i=j; i<n; ++i)

int main () {
	int N, K;
    cin >> N >> K;
    vector<string> s(N);
    rep(i, N) cin >> s[i];

    vector<vector<int>> cnt(N, vector<int>(26));
    rep(i, N) {
        for (auto &c : s[i]) ++cnt[i][c-'a'];
    }

    int ans = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        vector<int> num(26);
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                rep(j, 26) num[j] += cnt[i][j];
            }
        }

        int x = 0;
        rep(j, 26) {
            if (num[j] == K) ++x;
        }
        ans = max(ans, x);
    }

    printf("%d\n", ans);
	return 0;
}