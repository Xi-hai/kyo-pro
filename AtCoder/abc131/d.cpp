#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

bool comp(const PII &x, const PII &y) {
    return x.second < y.second;
}

int main() {
    int n; cin >> n;
    VI a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<PII> p(n);
    rep(i, n) {
        p[i].first = a[i];
        p[i].second = b[i];
    }

    sort(p.begin(), p.end(), comp);
    int time = 0;
    bool ans = true;
    rep(i, n) {
        time += p[i].first;
        if (time > p[i].second) {
            ans = false;
            break;
        }
    }
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}