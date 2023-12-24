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

int main() {
    int t; cin >> t;
    rep(i, t) {
        string s; cin >> s;
        int n=s.size(), cost=abs(s[0]-s[n-1]);

        if (n == 2) {
            printf("%d 2\n1 2\n", cost);
            continue;
        }

        VVI mem(n-2, VI(2));
        rep(j, 1, n-1) {
            mem[j-1][0] = s[j];
            mem[j-1][1] = j+1;
        }
        sort(all(mem));

        VI ans(0);
        bool rev=false;
        if (s[0] > s[n-1]) {
            swap(s[0], s[n-1]);
            rev=true;
        }
        rep(j, n-2) {
            if (mem[j][0] < (int)s[0]) continue;
            if (mem[j][0] > (int)s[n-1]) {
                break;
            }
            ans.push_back(mem[j][1]);
        }

        if (rev) reverse(all(ans));
        ans.push_back(n);

        int m=ans.size();
        printf("%d %d\n1", cost, m+1);
        rep(j, m) printf(" %d", ans[j]);
        printf("\n");
    }
    return 0;
}