#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

void swap(char *x, char *y) {
    char *temp = x;
    x = y;
    y = temp;
}

int main() {
    int N, Q, t, a, b;
    string S;
    cin >> N >> S >> Q;
    bool swap_check = false;

    rep(i, Q) {
        cin >> t >> a >> b;
        if (t == 1) {
            if (swap_check) {
                a = (a + N - 1) % (2*N);
                b = (b + N - 1) % (2*N);
                swap(S[a], S[b]);
            } else {
                swap(S[a-1], S[b-1]);
            }
        } else {
            swap_check = (swap_check ? 0 : 1);
        }
    }

    if (swap_check) {
        cout << S.substr(N);
        cout << S.substr(0, N) << endl;
    } else {
        cout << S << endl;
    }
    return 0;
}