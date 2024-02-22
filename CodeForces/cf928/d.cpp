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

const int MAX = (1LL << 31) - 1;

int main() {
    int t; cin >> t;
    rep(t) {
        int n, ans = 0; cin >> n;
        VI a(n);
        unordered_map<int, int> dict;
        rep(i, n) {
            cin >> a[i];
            if (dict.count(a[i])) {
                dict[a[i]]++;
            } else {
                dict[a[i]] = 1;
            }
        }

        rep(i, n) {
            if ((!dict.count(a[i])) || dict[a[i]] == 0) continue;
            int k = a[i]^MAX;
            if (dict.count(k) && dict[k] > 0) {
                dict[k] -= 1;
            }
            dict[a[i]]--;
            ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}