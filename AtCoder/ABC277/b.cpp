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
    int n; cin >> n;
    VS s(n);
    rep(i, n) cin >> s[i];

    vector<char> suit(4), num(13);
    suit = {'H', 'D', 'C', 'S'};
    num = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    set<string> st;
    bool ans=true;
    rep(i, n) {
        bool b_suit=false;
        rep(j, 4) {
            if (s[i][0] == suit[j]) b_suit=true;
        }
        if (!b_suit) {
            ans=false;
            break;
        }

        bool b_num=false;
        rep(j, 13) {
            if (s[i][1] == num[j]) b_num=true;
        }
        if (!b_num) {
            ans=false;
            break;
        }

        if (st.count(s[i])) {
            ans=false;
            break;
        }
        st.insert(s[i]);
    }

    printf(ans ? "Yes\n" : "No\n");
    return 0;
}