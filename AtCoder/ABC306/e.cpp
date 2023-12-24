// 解説AC
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)


int k;
multiset<int> x, y; // x: Bの先頭からk個, y: それ以外
ll s; // xに含まれる要素の総和=f(A)

void balance() {
    while (x.size() < k) {
        auto iy=y.end(); iy--; // *iy: yの最大要素
        x.insert((*iy));
        s += (*iy);
        y.erase(iy);
    }

    // 空になったら操作できないので終了
    if (x.empty() || y.empty()) {
        return;
    }

    while (1) {
        auto ix = x.begin();
        auto iy = y.end(); iy--;
        int ex = (*ix);
        int ey = (*iy);

        // xの最小要素 >= yの最大要素ならソート完了
        if (ex >= ey) {
            break;
        }

        // xの最小要素とyの最大要素を入れ替える
        s += (ey - ex);
        x.erase(ix);
        y.erase(iy);
        x.insert(ey);
        y.insert(ex);
    }
}

void add(int v) {
    // とりあえずyに入れて、必要なら入れ替える
    y.insert(v);
    balance();
}

void erase(int v) {
    auto ix = x.find(v);
    if (ix != x.end()) {
        // vがxに含まれる
        s -= v;
        x.erase(ix);
    }
    else {
        y.erase(y.find(v));
    }
    balance();
}

int main() {
    int n, q; scanf("%d %d %d", &n, &k, &q);
    VI a(n);
    // 最初は全部0
    rep(i, k) x.insert(0);
    rep(i, n-k) y.insert(0);
    s = 0;
    rep(q) {
        int p, w;
        scanf("%d %d", &p, &w);
        p--;
        add(w);
        erase(a[p]);
        a[p] = w;
        printf("%lld\n", s);
    }
    return 0;
}