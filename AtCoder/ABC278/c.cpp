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
    int n, q, t, a, b;
    scanf("%d %d", &n, &q);
    vector<set<int>> follows(1010101);
    map<int, int> mp;
    int k=0;

    rep(q) {
        scanf("%d %d %d", &t, &a, &b);

        if (!mp.count(a)) {
            mp[a] = k;
            k++;
        }

        if (t==1) follows[mp[a]].insert(b);
        else if (t==2) follows[mp[a]].erase(b);
        else {
            if (!mp.count(b)) {
                mp[b] = k;
                k++;
            }

            if (follows[mp[a]].count(b) && follows[mp[b]].count(a)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}