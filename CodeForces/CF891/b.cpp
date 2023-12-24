#include <bits/stdc++.h>
using namespace std;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

int main() {
    int t; scanf("%d", &t);
    rep(t) {
        string str; cin >> str;
        string cp = str;
        reverse(all(str));
        int len = str.size(), last_update = -1;
        bool digit_up = false;
        rep(i, len-1) {
            if (str[i] >= '5' || (str[i] == '4' && digit_up)) {
                digit_up = true;
                str[i] = '0';
                last_update = i;
            }
            else if (digit_up) {
                str[i]++;
                digit_up = false;
            }
            else {
                digit_up = false;
            }
        }
        if (str[len-1] >= '5' || (str[len-1] == '4' && digit_up)) {
            str[len-1] = '0';
            str.push_back('1');
            last_update = len-1;
        }
        else if (digit_up) {
            str[len-1]++;
        }
        rep(i, last_update) {
            str[i] = '0';
        }
        reverse(all(str));
        cout << str << "\n";
    }
    return 0;
}