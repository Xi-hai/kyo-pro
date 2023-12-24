#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0; i<n; ++i)
#define repi(i, j, n) for (int i=j; i<n; ++i)

int main () {
	string s;
    cin >> s;
    int n = s.size();
    bool upper = false, lower = false;
    rep(i, n) {
        if ('A' <= s[i] && s[i] <= 'Z') upper = true;
        else lower = true;
        repi(j, i+1, n) {
            if (s[i] == s[j]) goto NO;
        }
    }

    if (upper && lower) printf("Yes\n");
    else {
        NO:
        printf("No\n");
    }
	return 0;
}