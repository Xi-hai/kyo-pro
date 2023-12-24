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
const VI dy = {0, 1, 0, -1};
const VI dx = {1, 0, -1, 0};
const VI dy8 = {0, 1, 1, 1, 0, -1, -1, -1};
const VI dx8 = {1, 1, 0, -1, -1, -1, 0, 1};

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {a = b; return true;}
    return false;
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {a = b; return true;}
    return false;
}

void print_as_bin(int n) {
    string res;
    while (n>0) {
        res += (n%2 ? '1' : '0');
        n /= 2;
    }
    reverse(all(res));
    printf("%s", res.c_str());
}

int main() {
    int k; cin >> k;
    string s, t;
    cin >> s >> t;
    VI tak(10), aoki(10), remain(10, k);
    rep(i, 4) {
        tak[ s[i] - '0' ]++;
        remain[ s[i] - '0' ]--;
        aoki[ t[i] - '0' ]++;
        remain[ t[i] - '0' ]--;
    }

    VI point_tak(10), point_aoki(10); // 5枚目がiのときの点数
    rep(i, 1, 10) {
        tak[i]++;
        aoki[i]++;
        rep(j, 1, 10) {
            int temp = j;
            rep(tak[j]) temp *= 10;
            point_tak[i] += temp;
            temp = j;
            rep(aoki[j]) temp *= 10;
            point_aoki[i] += temp;
        }
        tak[i]--;
        aoki[i]--;
    }

    // 残り総枚数: 9*k - 8
    // 高橋君の5枚目がjのとき、高橋君が勝つ確率p[j]
    vector<double> p(10);
    rep(j, 1, 10) {
        if (remain[j] == 0) continue;
        remain[j]--;
        rep(i, 1, 10) {
            // 青木君が残り9*k-9枚からiを引いて、高橋君が勝つ
            if (remain[i] > 0 && point_tak[j] > point_aoki[i]) {
                p[j] += 1.0 * remain[i] / (9*k-9);
            }
        }
        remain[j]++;
    }

    // ans = sum[j=1~9]{ (高橋君がjを引く確率) * p[j] }
    double ans;
    rep(j, 1, 10) {
        ans += p[j] * remain[j] / (9*k-8);
    }

    printf("%.10lf\n", ans);
    return 0;
}