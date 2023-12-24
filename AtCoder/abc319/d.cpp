#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

const ll INFL = (1LL << 60);

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {a = b; return true;}
    return false;
}

ll binary_search(const VL &len, ll &max_len, ll &sum_len, ll &m) {
    int n = len.size();
    ll left = max_len-1, right = sum_len + n - 1;
    
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        ll row = 1, width = len[0];
        // ウィンドウの横幅がmidのときの行数
        rep(i, 1, n) {
            if (width + len[i] + 1 <= mid) {
                width += len[i] + 1;
            } else {
                row++;
                width = len[i];
            }
        }
        if (row <= m) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    int n;
    ll m;
    cin >> n >> m;
    ll sum_len = 0, max_len = 0;
    VL len(n);
    rep(i, n) {
        cin >> len[i];
        sum_len += len[i];
        chmax(max_len, len[i]);
    }

    cout << binary_search(len, max_len, sum_len, m) << "\n";
    return 0;
}