#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
template <class T> using V = vector<T>;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

int main() {
    int N; cin >> N;
    int M = N*N, x = N, y = N;
    rep(i, 2, N+1) {
        rep(j, 1, N+1) {
            if (i*j >= N && i+j <= M) {
                M = i+j-2;
                x = i;
                y = j;
                // printf("%d, %d\n", x, y);
            }
        }
    }
    cout << M << endl;

    VVI ans(M, VI(0));
    rep(i, M) {
        if (i < x-1) {
            
        }
    }
    return 0;
}