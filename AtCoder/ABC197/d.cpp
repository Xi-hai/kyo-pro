#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
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

int main() {
    int n; scanf("%d", &n);
    double x_0, y_0, x_n2, y_n2, x_1, y_1;
    cin >> x_0 >> y_0 >> x_n2 >> y_n2;
    double x_center = (x_0 + x_n2) / 2.0, y_center = (y_0 + y_n2) / 2.0;
    double theta = 2.0*M_PI / n;
    x_0 -= x_center; y_0 -= y_center;
    x_1 = x_center + x_0 * cos(theta) - y_0 * sin(theta);
    y_1 = y_center + x_0 * sin(theta) + y_0 * cos(theta);
    printf("%.7lf %.7lf\n", x_1, y_1);
    return 0;
}