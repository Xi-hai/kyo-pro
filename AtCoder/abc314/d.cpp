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
    int n, q;
    string s;
    cin >> n >> s >> q;

    VI t(q), x(q);
    vector<char> c(q);
    rep(i, q) {
        cin >> t[i] >> x[i] >> c[i];
        x[i]--;
    }

    string ans;
    rep(i, n) ans.append(" ");
    int sL = -1;
    for (int i=q-1; i>=0; i--) {
        if (t[i] == 1) {
            if (ans[x[i]] != ' ') continue;
            if (sL == -1) {
                ans[x[i]] = c[i];
            }
            else if (sL == 2) {
                ans[x[i]] = tolower(c[i]);
            }
            else {
                ans[x[i]] = toupper(c[i]);
            }
        }
        else if (t[i] == 2) {
            if (sL == -1) sL = 2;
        }
        else {
            if (sL == -1) sL = 3;
        }
    }

    rep(i, n) {
        if (ans[i] != ' ') continue;
        if (sL == -1) {
            ans[i] = s[i];
        }
        else if (sL == 2) {
            ans[i] = tolower(s[i]);
        }
        else {
            ans[i] = toupper(s[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}