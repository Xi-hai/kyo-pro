#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

int main() {
    int t; scanf("%d", &t);
    rep(t) {
        int n, k; scanf("%d %d", &n, &k);
        VI a(n), b(n);
        VI sorted_a(n), sorted_b(n);
        unordered_map<int, int> cnt;
        rep(i, n) {
            scanf("%d", &a[i]);
            sorted_a[i] = a[i];
        }
        rep(i, n) {
            scanf("%d", &b[i]);
            sorted_b[i] = b[i];
            cnt[b[i]]++;
        }
        sort(all(sorted_a));
        sort(all(sorted_b));

        rep(i, n) {
            int k = lower_bound(all(sorted_a), a[i]) - sorted_a.begin();
            rep(j, k, n) {
                if (cnt[sorted_b[j]] > 0) {
                    printf("%d ", sorted_b[j]);
                    cnt[sorted_b[j]]--;
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}