#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

int main() {
    int n, q;
    string s, t = "";
    cin >> n >> s >> q;
    rep(i, 26) t += (char)(i + 'a');

    while (q--) {
        char c, d;
        cin >> c >> d;
        rep(i, 26) {
            if (t[i] == c) {
                t[i] = d;
            }
        }
    }

    rep(i, n) {
        cout << t[(int)(s[i] - 'a')];
    }
    cout << "\n";
    return 0;
}