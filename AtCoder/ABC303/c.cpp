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
    int n, m, hp, k; scanf("%d %d %d %d", &n, &m, &hp, &k);
    string s; cin >> s;
    int x, y;
    set<VI> item;
    rep(m) {
        scanf("%d %d", &x, &y);
        item.insert({x, y});
    }

    int now_x = 0, now_y = 0;
    bool ans = true;
    rep(i, n) {
        //移動
        if (s[i] == 'R') now_x++;
        else if (s[i] == 'L') now_x--;
        else if (s[i] == 'U') now_y++;
        else now_y--;
        hp--;

        //回復, 終了
        if (hp < 0) {
            ans = false;
            break;
        }

        if (hp < k && item.count({now_x, now_y})) {
            hp = k;
            item.erase({now_x, now_y});
        }
    }

    printf(ans ? "Yes\n" : "No\n");
    return 0;
}