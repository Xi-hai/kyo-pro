#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0; i<n; ++i)
#define repi(i, j, n) for (int i=j; i<=n; ++i)

int main() {
    int N, M, K;
    cin >> N >> M;
    vector<int> a(M), b(M);
    rep(i, M) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }
    cin >> K;
    vector<int> c(K), d(K);
    rep(i, K) {
        cin >> c[i] >> d[i];
        --c[i];
        --d[i];
    }

    int ans = 0;
    //bit全探索
    rep(bit, (1<<K)) {
        vector<bool> ball(N, false); //皿iにボールが置かれているか
        rep(i, K) {
            //人iはtrueなら皿Ciに、falseなら皿Diにボールを置く
            if (bit & (1<<i)) {
                ball[c[i]] = true;
            } else {
                ball[d[i]] = true;
            }
        }

        //満たされる条件の個数をカウント
        int cnt = 0;
        rep(i, M) {
            if (ball[a[i]] && ball[b[i]]) ++cnt;
        }
        ans = max(ans, cnt);
    }

    printf("%d\n", ans);
    return 0;
}