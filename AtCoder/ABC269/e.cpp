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

int question(int A, int B, int C, int D) {
    int T;
    cout << "? " << A << " " << B << " " << C << " " << D << endl;
    cin >> T;
    return T;
}

int main() {
    //行方向と列方向でそれぞれ二分探索
    int N; cin >> N;
    int top=1, bottom=N+1, left=1, right=N+1; //解の存在範囲は[top, bottom) & [left, right)

    //行を探す
    while (bottom - top > 1) {
        int mid = (top + bottom) / 2;
        int res = question(top, mid-1, 1, N);
        if (res == -1) return 0;
        if (res == mid - top) top = mid;
        else bottom = mid;
    }

    //列を探す
    while (right - left > 1) {
        int mid = (left + right) / 2;
        int res = question(1, N, left, mid-1);
        if (res == -1) return 0;
        if (res == mid - left) left = mid;
        else right = mid;
    }

    cout << "! " << top << " " << left << endl;
    return 0;
}