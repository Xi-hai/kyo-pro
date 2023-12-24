#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

const int INFI = (1 << 30);

int binary_search(const VL &v, ll key, int x) {
    int left = -1, right = (int)v.size();
    
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (v[mid] - v[x] == key) return mid;
        else if (v[mid] - v[x] > key) right = mid;
        else left = mid;
    }
    return INFI;
}

int main() {
    int n; ll p, q, r;
    scanf("%d %lld %lld %lld", &n, &p, &q, &r);
    VL a(n), sum(n+1);
    rep(i, n) {
        scanf("%lld", &a[i]);
        sum[i+1] = sum[i] + a[i];
    }

    bool ans = false;
    rep(x, n) {
        int y = binary_search(sum, p, x);
        if (y > n) continue;
        int z = binary_search(sum, q, y);
        if (z > n) continue;
        int w = binary_search(sum, r, z);
        if (w > n) continue;
        ans = true;
        break;
    }

    printf(ans ? "Yes\n" : "No\n");
    return 0;
}
