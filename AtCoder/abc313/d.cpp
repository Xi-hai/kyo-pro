#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

int main() {
    int n, k; cin >> n >> k;
    VI ans(n, 0);
    if (k == 1) {
        rep(i, n) {
            cout << "? " << i+1 << endl;
            cin >> ans[i];
        }
    } else {
        int subsum_to_k = 0;
        // まず先頭からk+1個を特定
        rep(i, k+1) {
            cout << "?";
            rep(j, k+1) {
                if (j != i) cout << " " << j+1;
            }
            cout << endl;
            cin >> ans[i];
            if (ans[i] == -1) return 0;
            ans[i] %= 2;
            subsum_to_k += ans[i];
        }

        subsum_to_k %= 2;
        rep(j, k+1) {
            ans[j] ^= subsum_to_k;
        }
        subsum_to_k ^= (ans[k] ^ ans[k-1]); // 先頭k-1個の和

        // 既に特定した中の先頭k-1個を使って、残りのn-k-1個を特定
        rep(i, k+1, n) {
            cout << "?";
            rep(j, k-1) cout << " " << j+1;
            cout << " " << i+1 << endl;
            cin >> ans[i];
            if (ans[i] == -1) return 0;
            ans[i] = (ans[i]%2) ^ subsum_to_k;
        }
    }

    cout << "!";
    rep(i, n) cout << " " << ans[i];
    cout << "\n";
    return 0;
}