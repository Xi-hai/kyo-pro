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
        int n; cin >> n;
        set<string> s1, s2, s3;
        string s;
        rep(j, n) {
            cin >> s;
            s1.insert(s);
        }
        rep(j, n) {
            cin >> s;
            s2.insert(s);
        }
        rep(j, n) {
            cin >> s;
            s3.insert(s);
        }

        vector<int> point(3);
        for (auto st : s1) {
            if (!s2.count(st)) {
                if (!s3.count(st)) {
                    point[0] += 3;
                } else {
                    point[0]++;
                }
            }
            else if (!s3.count(st)) {
                point[0]++;
            }
        }

        for (auto st : s2) {
            if (!s3.count(st)) {
                if (!s1.count(st)) {
                    point[1] += 3;
                } else {
                    point[1]++;
                }
            }
            else if (!s1.count(st)) {
                point[1]++;
            }
        }

        for (auto st : s3) {
            if (!s1.count(st)) {
                if (!s2.count(st)) {
                    point[2] += 3;
                } else {
                    point[2]++;
                }
            }
            else if (!s2.count(st)) {
                point[2]++;
            }
        }

        printf("%d %d %d\n", point[0], point[1], point[2]);
    }
    return 0;
}