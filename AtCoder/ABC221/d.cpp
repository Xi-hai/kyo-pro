#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
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
    vector<int> a(n), b(n);
    map<int, int> mp;
    rep(i, n) {
        cin >> a[i] >> b[i];
        mp[a[i]]++;
        mp[a[i]+b[i]]--;
    }
    
    int start = 1, people = 0;
    VI day_cnt(n+1);
    for (auto &p : mp) {
        day_cnt[people] += p.first - start;
        people += p.second;
        start = p.first;
    }

    rep(i, 1, n+1) printf((i<n ? "%d " : "%d\n"), day_cnt[i]);
    return 0;
}