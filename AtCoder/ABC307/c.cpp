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
    int H_A, W_A, H_B, W_B, H_X, W_X;
    int cnt_A = 0, cnt_B = 0;
    scanf("%d %d", &H_A, &W_A);
    VS S_A(H_A);
    rep(i, H_A) {
        cin >> S_A[i];
        rep(j, W_A) {
            if (S_A[i][j] == '#') cnt_A++;
        }
    }
    scanf("%d %d", &H_B, &W_B);
    VS S_B(H_B);
    rep(i, H_B) {
        cin >> S_B[i];
        rep(j, W_B) {
            if (S_B[i][j] == '#') cnt_B++;
        }
    }
    scanf("%d %d", &H_X, &W_X);
    VS S_X(H_X);
    rep(i, H_X) cin >> S_X[i];

    bool ans = false;
    rep(dh_A, 20) {
        rep(dw_A, 20) {
            rep(dh_B, 20) {
                rep(dw_B, 20) {
                    VVI S_C(30, VI(30));
                    rep(i, H_A) {
                        rep(j, W_A) {
                            if (S_A[i][j] == '#') {
                                S_C[i+dh_A][j+dw_A]++;
                            }
                        }
                    }
                    rep(i, H_B) {
                        rep(j, W_B) {
                            if (S_B[i][j] == '#') {
                                S_C[i+dh_B][j+dw_B]++;
                            }
                        }
                    }

                    bool temp = true;
                    int cnt = 0;
                    rep(i, H_X) {
                        rep(j, W_X) {
                            if (S_X[i][j] == '#' && S_C[i+10][j+10] == 0) {
                                temp = false;
                                goto NEXT;
                            }
                            if (S_X[i][j] == '.' && S_C[i+10][j+10] != 0) {
                                temp = false;
                                goto NEXT;
                            }
                            cnt += S_C[i+10][j+10];
                        }
                    }
                    NEXT:
                    if (temp && cnt == cnt_A + cnt_B) {
                        ans = true;
                        goto OUT;
                    }
                }
            }
        }
    }

    OUT:
    printf(ans ? "Yes\n" : "No\n");
    return 0;
}